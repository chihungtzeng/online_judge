#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAXN 21
#define VERBOSE 0
#define DEBUG 0


struct Point{
	short rfrom, cfrom;
};


int compareUUC(short a, short b){
	if(a == b) return 0;
	else return a - b;
}

 

int altitude[MAXN][MAXN];
char allow[MAXN][MAXN][MAXN][MAXN];
short dist[MAXN][MAXN];
short nRow, nCol;
short rfrom, rto, cfrom , cto;
struct Point source[MAXN][MAXN];


short findPath(){
	short i, j, r, c;
	short src, head, tail;
	short queue[512];
	
	
	memset(dist, 0x7f, sizeof(short)*MAXN*MAXN);	
	 
	
	src = (rfrom << 5) + cfrom;	
	queue[0] = src;
	
	dist[rfrom][cfrom] = 0;
	source[rfrom][cfrom].rfrom = 0;
	source[rfrom][cfrom].cfrom = 0;
	head = 0;
	tail = 1;
	while(head < tail){
		short rnext, cnext;
		src = queue[head++];
		r = src >> 5;
		c = src & 0x1f;
		for(i=-1; i<=1; i++){
			for(j=-1; j<=1; j++){
				if(abs(i+j) != 1) continue;
				
				rnext = r + i;
				cnext = c + j; 
				
				/*if no match, the routing from (r, c) to (r+i, c+j) is not allowed*/
				if(allow[r][c][rnext][cnext] == 0) continue;
								
				if(dist[r][c] + 1 < dist[rnext][cnext]){
					dist[rnext][cnext] = dist[r][c] + 1;
					source[rnext][cnext].rfrom = r;
					source[rnext][cnext].cfrom = c;
					queue[tail] = (rnext << 5) + cnext;
					tail++;
				}
			}
		}
	}
	
	

	return tail;
}

int main(){
	char firstCase = 1;
	FILE *fp;

	fp = stdin;	
	
	while(2 == fscanf(fp, "%hd %hd",&nRow, &nCol)){
		short i, j, street[2], avenue[2];
		memset(allow, 0, 194481);
		
		for(i=1; i<= nRow; i++){
			for(j=1; j<=nCol; j++){
				fscanf(fp, "%d", &altitude[i][j]);
			}
		}
		while(4 == fscanf(fp, "%hd %hd %hd %hd", &street[0], &avenue[0], &street[1], &avenue[1])){
			
			if( (street[0] == 0) && (avenue[0] == 0) && (street[1] == 0) && (avenue[1] == 0)){
				break;
			}
			if(street[0] == street[1]){
				/*the same row*/						
				if(avenue[0] < avenue[1]){
					/*from west to east*/
					for(i=avenue[0]; i<avenue[1]; i++){
						if(abs(altitude[street[0]][i] - altitude[street[0]][i+1]) <= 10){
							allow[street[0]][i][street[0]][i+1] = 1;
						}
					}
				}
				else{
					/*from east to west*/
					for(i=avenue[0]; i > avenue[1]; i--){
						if(abs(altitude[street[0]][i] - altitude[street[0]][i-1]) <= 10){
							allow[street[0]][i][street[0]][i-1] = 1;
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
							allow[i][avenue[0]][i+1][avenue[0]] = 1;
						}
					}
				}
				else{
					/*from south to north*/
					for(i=street[0]; i > street[1]; i--){
						if(abs(altitude[i][avenue[0]] - altitude[i-1][avenue[0]]) <= 10){
							allow[i][avenue[0]][i-1][avenue[0]] = 1;
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
		
	}
	return 0;
}
