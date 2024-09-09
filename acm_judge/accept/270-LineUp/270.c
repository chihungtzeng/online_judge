#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LEN 1000
#define MAX 701
#define DEBUG 0

struct Point{
	int x, y;
};

int compareDouble(const void *a, const void *b){
	double u, v;
	u = *(double *)a;
	v = *(double *)b;
	if(u < v) return -1;
	else if (u == v) return 0;
	else return 1;
}

int comparePoint(const void *a, const void *b){
	struct Point *u, *v;
	u = (struct Point *)a;
	v = (struct Point *)b;
	if(u->x != v->x) return u->x - v->x;
	else return u->y - v->y;
}

double calSlope(struct Point p1, struct Point p2){
	if(p1.x == p2.x) return 1000000000.0;
	return (double)(p1.y - p2.y)/(p1.x - p2.x);
}

int main(){
	short nTest, nPoint, ans, count, i, j, k;
	
	char line[LEN];
	double slope[MAX];
	struct Point point[MAX];
	int nSlope;
	char *tok, done, firstCase = 1;
	FILE *fp;
	
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;

	fgets(line, LEN, fp);
	nTest = atoi(line);
	fgets(line, LEN, fp); /*the first empty line*/
	while(nTest >= 1){
		nTest--;		
		nPoint = 0 ;
		done = 0;
		while(!done){
			if(NULL == fgets(line, LEN, fp)){
				done = 1;
				continue;
			}
			
			tok = strtok(line, " \n");
			if(tok == NULL) {
				done = 1;
				continue;
			}
			
			point[nPoint].x = atoi(tok);
			tok = strtok(NULL, " \n");
			point[nPoint].y = atoi(tok);
			nPoint++;
		}
		qsort(point, nPoint, sizeof(struct Point), comparePoint);
		ans = 0;
		for(i=0; i<nPoint; i++){
			nSlope = 0;
			for(j=i+1; j<nPoint; j++){				
				slope[nSlope++] = calSlope(point[i], point[j]);
			/*	printf("slope=%lf for (%d %d) (%d %d)\n", slope[nSlope -1], point[i].x, point[i].y, point[j].x, point[j].y);*/	
			}
			qsort(slope, nSlope, sizeof(double), compareDouble);
			/*
			for(j=0; j<nSlope; j++){
				printf("%lf ",slope[j]);
			}
			printf("\n");
			*/
			count = 1;
			
			for(j=1; j<nSlope; j++){
				if(fabs(slope[j] - slope[j-1]) <= 1e-10){
					count++;
				}
				else{
					if(count + 1 > ans){
						ans = count + 1;
					}
					count = 1;
				}
			}
			if(count + 1 > ans){
				ans = count + 1;
			}
		}
		
		if(firstCase){
			firstCase = 0;
		}
		else{
			printf("\n");
		}
		printf("%hd\n",ans);
	
	}
	return 0;
}