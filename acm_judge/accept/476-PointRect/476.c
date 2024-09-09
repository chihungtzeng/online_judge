#include <stdio.h>
#include <stdlib.h>
#define MAX 11
#define LINELEN 512 
#define ENDPOINT "9999.9"

struct Point {
	double x, y;
};

struct Rectangle {
	struct Point ul, lr;
};

struct Rectangle rect[MAX];
int nRect;
int insideRect[MAX];

int isInside(struct Point query, struct Rectangle r){
	if(query.x <= r.ul.x) return 0;
	if(query.x >= r.lr.x) return 0;
	if(query.y <= r.lr.y) return 0;
	if(query.y >= r.ul.y) return 0;
	return 1;
}

int inside(struct Point query){
	int nInside = 0;
	int i;
	for(i=1; i<=nRect; i++){
		if(isInside(query, rect[i])){
			insideRect[nInside++] = i;
		}
	}
	return nInside;
}

void solve(int pointIndex, struct Point query){
	int nOverlap, i;
	nOverlap = inside(query);
	for(i=0; i<nOverlap; i++){
		printf("Point %d is contained in figure %d\n", pointIndex, insideRect[i]);
	}
	if(nOverlap == 0){
		printf("Point %d is not contained in any figure\n", pointIndex);
	}
}

int main(){
	char token[2][32];
	int read = 1, nPoint = 1;
	struct Point query;
	/*read rectangle*/
	nRect = 1;
	while(read){
		scanf("%s", token[0]);
		if(token[0][0] == 'r'){
			scanf("%lf %lf %lf %lf", &rect[nRect].ul.x, &rect[nRect].ul.y, &rect[nRect].lr.x, &rect[nRect].lr.y);
			nRect++; 
		} else {
			read = 0;
		}
	}
	#if 0
	for(read=0; read<nRect; read++){
		printf("(%lf %lf) (%lf %lf)\n", rect[read].ll.x, rect[read].ll.y, rect[read].ur.x, rect[read].ur.y);
	}
	#endif

	/*read point*/
	while(2 == scanf("%s %s", token[0], token[1])){
		if( (strcmp(token[0], ENDPOINT) == 0) && (strcmp(token[1], ENDPOINT) == 0)){
			break;
		}
		query.x = atof(token[0]);
		query.y = atof(token[1]);
		#if 0
		printf("query is (%lf %lf)\n", query.x , query.y);
		#endif
		solve(nPoint, query);
		nPoint++;
	}	
	
	return 0;
}
