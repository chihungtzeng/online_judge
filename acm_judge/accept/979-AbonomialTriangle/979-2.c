/*AC 0.092s*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAX 2000
#define VERBOSE 0

struct point{
	int x, y;
};

struct segment {
	int idx1, idx2;
	long dist;
};

int compareSegment(const void *a, const void *b){
	struct segment *x, *y;
	x = (struct segment *)a;
	y = (struct segment *)b;
	return (x->idx1 - y->idx1)*MAX + (x->idx2 - y->idx2); 
}

struct segment *newSegment(int i, int j, long dist){
	struct segment *s;
	s = (struct segment *) malloc(sizeof(struct segment));
	s->idx1 = i;
	s->idx2 = j;
	s->dist = dist;
	return s;
}

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

int max(int a, int b){
	if(a>b) return a;
	else return b;
}

int min(int a, int b){
	if (a > b) return b;
	else return a;
}

int main(){
	int nPoint;
	struct point p[MAX];
	struct point gt[3];
	char first = 1;
	short x, y, i, j, k, done;
	short ans[3];
	long s[3]; /*s is the length for the gold triangle*/
	long ltmp, distTmp[3];
	struct point output[3];
	struct segment *segTmp, *target[3];
	struct segment **candidate;
	int nCandidate;
	void *segRoot;

	candidate = (struct segment **) malloc(sizeof(struct segment *)*MAX*MAX);
	
	while(2 == scanf("%hd %hd", &x, &y)){
		segRoot = NULL;
		nCandidate = 0;
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
				 ltmp = distSquare(p[i].x - p[j].x, p[i].y - p[j].y);
				 if((ltmp == s[0]) || (ltmp == s[1]) || (ltmp == s[2])){
				 	segTmp = newSegment(i, j, ltmp);
				 	candidate[nCandidate++] = segTmp;
				 	tsearch(segTmp, &segRoot, compareSegment);
				 }
			}
		}
		if(VERBOSE){
			printf("find %d candidates\n",nCandidate);
		}
		/*Now begin searching for the gold triangle*/
		done = 0;
		

		while((!done) && (nCandidate > 0)){
			struct segment *match0, *match1;
			nCandidate--;
			i = candidate[nCandidate]->idx1;
			j = candidate[nCandidate]->idx2;
			for(k = 0; (k<nPoint) && (!done); k++){
				if((k == i) || (k == j)){
					continue;
				}
				target[0] = newSegment(min(i, k), max(i, k), 0);				
				match0 = *(struct segment **) tsearch((void *) target[0], &segRoot, compareSegment);
				if((match0 == NULL) || (match0 == target[0])){
					tdelete(target[0], &segRoot, compareSegment);
					free(target[0]);
					continue;
				}
				target[1] = newSegment(min(j, k), max(j, k), 0);
				match1 = *(struct segment **) tsearch((void *) target[1], &segRoot, compareSegment);
				if((match0 == NULL) || (match0 == target[0])){
					tdelete(target[1], &segRoot, compareSegment);
					free(target[1]);
					continue;
				}
				distTmp[0] = match0->dist;
				distTmp[1] = match1->dist;
				distTmp[2] = candidate[nCandidate]->dist;
				qsort(distTmp, 3, sizeof(long), compareLong);
				if(VERBOSE){
					printf("found perimeters: %ld %ld %ld\n", distTmp[0], distTmp[1],distTmp[2]);
				}
				if(equivalent(distTmp, s)){
					done = 1;
					ans[0] = i;
					ans[1] = j;
					ans[2] = k;
				}
				tdelete(target[0], &segRoot, compareSegment);
				free(target[0]);
				tdelete(target[1], &segRoot, compareSegment);
				free(target[1]);
			}
		}		
		if(!done){
			printf("No gold triangle!\n");
		}
		memcpy(&output[0], &p[ans[0]], sizeof(struct point));
		memcpy(&output[1], &p[ans[1]], sizeof(struct point));
		memcpy(&output[2], &p[ans[2]], sizeof(struct point));
		qsort(output, 3, sizeof(struct point), comparePoint);
		for(i=0; i<3; i++){
			printf("%d %d\n", output[i].x, output[i].y);
		}
		tdestroy(segRoot, free);
	}
		
	return 0;
}
