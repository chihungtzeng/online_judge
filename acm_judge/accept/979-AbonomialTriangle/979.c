#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000
#define VERBOSE 0

struct point{
	int x, y;
};


void setPoint(struct point *p, int x, int y){
	p->x = x;
	p->y = y;
}

long distSquare(int x, int y){
	return x*x + y*y;
}

int compareLong(const void *a, const void *b){
	return *(long *)a - *(long *)b;
}

int comparePoint(const void *a, const void *b){
	struct point *p, *q;
	p = (struct point *)a;
	q = (struct point *)b;
	return (p->x - q->x)*MAX + (p->y - q->y);
}

int equivalent(long *a1, long *a2){
	if ((a1[0] == a2[0]) && (a1[1] == a2[1]) && (a1[2] == a2[2])){
		return 1;
	}
	return 0;
}

int main(){
	int nPoint;
	struct point p[MAX];
	struct point gt[3];
	char first = 1;
	short x, y, i, j, k, done;
	short ans[3];
	long s[3]; /*s is the length for the gold triangle*/
	long *distArray;
	struct point output[3];
	
	distArray = (long *) malloc(sizeof(long)*MAX*MAX);
	while(2 == scanf("%hd %hd", &x, &y)){
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		setPoint(&gt[0], x, y);
		for(i=1; i<3; i++){
			scanf("%hd %hd", &x, &y);
			setPoint(&gt[i], x, y);
		}
		scanf("%d",&nPoint);
		for(i=0; i<nPoint; i++){
			scanf("%hd %hd", &x, &y);
			setPoint(&p[i], x, y);
		}
		s[0] = distSquare(gt[0].x - gt[1].x, gt[0].y - gt[1].y);
		s[1] = distSquare(gt[0].x - gt[2].x, gt[0].y - gt[2].y);
		s[2] = distSquare(gt[1].x - gt[2].x, gt[1].y - gt[2].y);
		if(VERBOSE){
			printf("The gold triangle is\n");
			for(i=0; i<3; i++){
				printf("%d %d\n",gt[i].x, gt[i].y);
			}
			printf("the triangle perimeter: %ld %ld %ld\n",s[0],s[1], s[2]);
		}
		qsort(s, 3, sizeof(long), compareLong);
		for(i=0; i<nPoint; i++){
			for(j=i+1; j<nPoint; j++){
				 distArray[i*MAX + j] = distSquare(p[i].x - p[j].x, p[i].y - p[j].y);
			}
		}
		/*Now begin searching for the gold triangle*/
		done = 0;
		long tmp[3];
		for(i=0; (i<nPoint) && (!done); i++){
			for(j=i+1; (j<nPoint) && (!done); j++){
				for(k=j+1; (k<nPoint) && (!done); k++){
					tmp[0] = distArray[i*MAX + j];
					tmp[1] = distArray[i*MAX + k];
					tmp[2] = distArray[j*MAX + k];
					qsort(tmp, 3, sizeof(long), compareLong);
					if(equivalent(tmp, s)){
						done = 1;
						ans[0] = i;
						ans[1] = j;
						ans[2] = k;
					}
					if(VERBOSE){
						printf("the triangle perimeter: %ld %ld %ld\n",tmp[0],tmp[1], tmp[2]);
					}
				}
			}
		}
		memcpy(&output[0], &p[ans[0]], sizeof(struct point));
		memcpy(&output[1], &p[ans[1]], sizeof(struct point));
		memcpy(&output[2], &p[ans[2]], sizeof(struct point));
		qsort(output, 3, sizeof(struct point), comparePoint);
		for(i=0; i<3; i++){
			printf("%d %d\n", output[i].x, output[i].y);
		}
	}
	free(distArray);	
	return 0;
}