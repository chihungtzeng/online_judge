/*AC 0.328s*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAXN 21
#define VERBOSE 0
#define DEBUG 0

struct OneWayPath{
	short rfrom, cfrom, rto, cto;
};

struct Point{
	short rfrom, cfrom;
};

struct OneWayPath *newOneWayPath(short rfrom, short cfrom, short rto, short cto){
	struct OneWayPath *p;
	p = (struct OneWayPath *) malloc(sizeof(struct OneWayPath));
	p->rfrom = rfrom;
	p->cfrom = cfrom;
	p->rto = rto;
	p->cto = cto;
	return p;
}

int compareUUC(short a, short b){
	if(a == b) return 0;
	else if (a < b) return -1;
	else return 1;
}

void swap(short *a, short *b){
	short c;
	c = *a;
	*a = *b;
	*b = c;
}
 

int compareOneWayPath(const void *a, const void *b){
	struct OneWayPath *x, *y;
	x = (struct OneWayPath *)a;
	y = (struct OneWayPath *)b;
	if(compareUUC(x->rfrom, y->rfrom)) return compareUUC(x->rfrom, y->rfrom);
	else if (compareUUC(x->cfrom, y->cfrom)) return compareUUC(x->cfrom, y->cfrom);
	else if (compareUUC(x->rto, y->rto)) return compareUUC(x->rto, y->rto);
	else return compareUUC(x->cto, y->cto);
}

int altitude[MAXN][MAXN];
void *oneWayPathTree;
short dist[MAXN][MAXN];
short nRow, nCol;
short route[MAXN];
short rfrom, rto, cfrom , cto;
struct Point source[MAXN][MAXN];


short findPath(){
	struct OneWayPath *query, *match;
	char color[MAXN][MAXN]; /*for BFS traversal*/
	short i, j, r, c;
	short src, target, head, tail;
	short queue[1000];
	
	
	memset(dist, 0x7f, sizeof(short)*MAXN*MAXN);	
	memset(color, 0, sizeof(char)*MAXN*MAXN); 
	
	src = rfrom*MAXN + cfrom;	
	queue[0] = src;
	color[rfrom][cfrom] = 1;
	dist[rfrom][cfrom] = 0;
	source[rfrom][cfrom].rfrom = 0;
	source[rfrom][cfrom].cfrom = 0;
	head = 0;
	tail = 1;
	while(head < tail){
		short rnext, cnext;
		src = queue[head++];
		r = src / MAXN;
		c = src % MAXN;
		for(i=-1; i<=1; i++){
			for(j=-1; j<=1; j++){
				if(abs(i+j) != 1) continue;
				
				rnext = r + i;
				cnext = c + j; 
				query = newOneWayPath(r, c, rnext, cnext);
				match = tfind(query, &oneWayPathTree, compareOneWayPath);
				free(query);
				/*if no match, the routing from (r, c) to (r+i, c+j) is not allowed*/
				if(match == NULL) continue;
								
				if(color[rnext][cnext] == 0){
					color[rnext][cnext] = 1;
					dist[rnext][cnext] = dist[r][c] + 1;
					source[rnext][cnext].rfrom = r;
					source[rnext][cnext].cfrom = c;
					queue[tail] = rnext*MAXN + cnext;
					tail++;
					if(VERBOSE){
						printf("from (%hd %hd) to (%hd %hd), dist[%hd][%hd]=%hd\n",r, c, rnext, cnext, rnext, cnext, dist[rnext][cnext]);
					}
				}
			}
		}
	}
	
	

	return tail;
}

int main(){
	char firstCase = 1;
	FILE *fp;

	fp = (DEBUG)? fopen("in.txt","r") : stdin;	
	
	while(2 == fscanf(fp, "%hd %hd",&nRow, &nCol)){
		short alt;
		short i, j, street[2], avenue[2];
		
		oneWayPathTree = NULL;
		for(i=1; i<= nRow; i++){
			for(j=1; j<=nCol; j++){
				fscanf(fp, "%d", &altitude[i][j]);
			}
		}
		while(4 == fscanf(fp, "%hd %hd %hd %hd", &street[0], &avenue[0], &street[1], &avenue[1])){
			struct OneWayPath *p;
			if( (street[0] == 0) && (avenue[0] == 0) && (street[1] == 0) && (avenue[1] == 0)){
				break;
			}
			if(street[0] == street[1]){
				/*the same row*/						
				if(avenue[0] < avenue[1]){
					/*from west to east*/
					for(i=avenue[0]; i<avenue[1]; i++){
						if(abs(altitude[street[0]][i] - altitude[street[0]][i+1]) <= 10){
							if(VERBOSE){
								printf("route: (%hd %hd) to (%hd %hd)\n", street[0], i, street[0], i+1);
							}
							p = newOneWayPath(street[0], i, street[0], i+1);
							tsearch(p, &oneWayPathTree, compareOneWayPath);
						}
					}
				}
				else{
					/*from east to west*/
					for(i=avenue[0]; i > avenue[1]; i--){
						if(abs(altitude[street[0]][i] - altitude[street[0]][i-1]) <= 10){
							if(VERBOSE){
								printf("route: (%hd %hd) to (%hd %hd)\n", street[0], i, street[0], i-1);
							}
							p = newOneWayPath(street[0], i, street[0], i-1);
							tsearch(p, &oneWayPathTree, compareOneWayPath);
						}
					}
				}
			}
			else if(avenue[0] == avenue[1]){
				/*column*/
				if(street[0] <= street[1]){
					/*from north to south*/
					for(i=street[0]; i<street[1]; i++){
						if(abs(altitude[i][avenue[0]] - altitude[i+1][avenue[0]]) <= 10){
							if(VERBOSE){
								printf("route: (%hd %hd) to (%hd %hd)\n", i, avenue[0], i+1, avenue[0]);
							}
							p = newOneWayPath(i, avenue[0], i+1, avenue[0]);
							tsearch(p, &oneWayPathTree, compareOneWayPath);
						}
					}
				}
				else{
					/*from south to north*/
					for(i=street[0]; i > street[1]; i--){
						if(abs(altitude[i][avenue[0]] - altitude[i-1][avenue[0]]) <= 10){
							if(VERBOSE){
								printf("route: (%hd %hd) to (%hd %hd)\n", i, avenue[0], i-1, avenue[0]);
							}
							p = newOneWayPath(i, avenue[0], i - 1, avenue[0]);
							tsearch(p, &oneWayPathTree, compareOneWayPath);
						}
					}
				}
			}
		}
		/*get start/end and output answer*/
		while(4 == fscanf(fp, "%hd %hd %hd %hd",&rfrom, &cfrom, &rto, &cto)){
			if( (rfrom == 0) && (cfrom == 0) && (rto == 0) && (cto == 0)){
				break;
			}
			/*each output set is seperated by a blank line*/
			if(firstCase){
				firstCase = 0;
			}
			else {
				printf("\n");
			}
			
			if( (rfrom == rto) && (cfrom == cto)){
				printf("To get from %hd-%hd to %hd-%hd, stay put!\n",rfrom, cfrom, rto, cto);
				continue;	
			}
			findPath();
			if(VERBOSE){
				printf("-----------------\n");
				for(i=1; i<=nRow; i++){
					for(j=1; j<=nCol; j++){
						printf("%hd ", dist[i][j]);
					}
					printf("\n");
				}
			}
			if(dist[rto][cto] > MAXN*MAXN ){
				printf("There is no acceptable route from %hd-%hd to %hd-%hd.\n", rfrom, cfrom, rto, cto);
			}
			else{
				struct Point pre[MAXN*MAXN];
				short r=rto, c=cto, tmpr, tmpc;
				short nPoint = 0;
				while((r != 0) && (c != 0)){
					
					pre[nPoint].rfrom = r;
					pre[nPoint].cfrom = c;
					nPoint++;
					tmpr = r;
					tmpc = c;
					r = source[tmpr][tmpc].rfrom;
					c = source[tmpr][tmpc].cfrom;
				}
				printf("%hd-%hd",pre[nPoint-1].rfrom, pre[nPoint-1].cfrom);
				for(i=nPoint-2; i>=0; i--){
					printf(" to %hd-%hd",pre[i].rfrom, pre[i].cfrom);
				}
				printf("\n");
			}
			
		}
		tdestroy(oneWayPathTree, free);
	}
	return 0;
}
