#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100;

struct point{
	int x, y;
};

int arrangepoint(const void *a, const void *b){
	struct point *x, *y;
	x = (struct point *)a;
	y = (struct point *)b;
	return x->x - y->x;
}

double findIntersection(struct point p1, struct point p2, int py){
	double result = 0;
	double px;
	if (py - p1.y == 0){
		return 0.0;
	}
	px = p1.x +  ( (double) (p1.x - p2.x)*(py - p1.y) /(p1.y-p2.y) );
	return hypot(px - p1.x, py - p1.y);
}

int main(){
	struct point *turn;
	int nTurn, curPeak;
	int nTest, increasing;
	int i;
	double length;
	char line[MAX];
	
	scanf("%d",&nTest);
	
	while(nTest >= 1){
		nTest--;
		scanf("%d",&nTurn);
		turn = (struct point *) malloc(sizeof(struct point)*nTurn);
		for(i=0;i<nTurn;i++){
			scanf("%d %d", &turn[i].x, &turn[i].y);
		}
		qsort(turn, nTurn, sizeof(struct point), arrangepoint);
		length = 0;
		/*
		if(nTurn >= 2){
			length = hypot(turn[nTurn -1].x - turn[nTurn -2].x, turn[nTurn-1].y - turn[nTurn -2].y);
		}*/
		
		curPeak = 0;

		for(i=nTurn - 2; i>=0; i--){
			if( (turn[i].y > curPeak)){
				length += findIntersection(turn[i], turn[i+1], curPeak);
				curPeak = turn[i].y;
			}
		}
		printf("%.2f\n",length);
		free(turn);
	}
	
	return 0;
}