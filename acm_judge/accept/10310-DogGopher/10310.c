#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
	double x, y;
};

struct Point dogPos, gopherPos;
struct Point *holePos;
short nHole;

double squareSum(double a, double b){
	return a*a + b*b;
}

void solve(){
	double gDist, dDist;
	short i, idx;
	char canEscape = 0;
	for(i=0; (i<nHole) && !canEscape; i++){
		gDist = 4 * squareSum(holePos[i].x - gopherPos.x, holePos[i].y - gopherPos.y);
		dDist = squareSum(holePos[i].x - dogPos.x, holePos[i].y - dogPos.y);
		if(gDist <= dDist) {
			canEscape = 1;
			idx = i;
		}
	}
	
	
	#if 0
		
		printf("dog dist:%lf gopher dist:%lf idx=%hd\n", dDist, gDist, idx);
	#endif	
	
	if(canEscape){
		printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", holePos[idx].x, holePos[idx].y);
	} else {
		printf("The gopher cannot escape.\n");
				
	}
}

int main(){
	short i;
	

	while(1 == scanf("%hd", &nHole)){
		holePos = (struct Point *) malloc(sizeof(struct Point)*nHole);
		scanf("%lf %lf %lf %lf", &gopherPos.x, &gopherPos.y, &dogPos.x, &dogPos.y);
		for(i=0; i<nHole; i++){
			scanf("%lf %lf", &holePos[i].x, &holePos[i].y);
		}
		solve(); 
		free(holePos);
	}	
	
	return 0;
}