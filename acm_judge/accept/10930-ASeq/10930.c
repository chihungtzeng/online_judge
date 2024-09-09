#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define MAX 32
#define TRUE 1
#define FALSE 0
#define DEBUG 0

short *newShort(short a){
	short *p;
	p = (short *) malloc(sizeof(short));
	*p = a;
	return p;
}

int compareShort(const void * a, const void * b){
	return *(short *)a - *(short *)b;
}

int basicCheck(short nNum, short num[]){
	short i;
	if(num[0] < 1) return FALSE;
	for(i=1; i<nNum; i++){
		if(num[i] <= num[i-1]) return FALSE;
	}
	return TRUE;
}

void twalkAction(const void *rootp, const VISIT way, const int depth){
	if((way == leaf) || (way == postorder)){
		short s;
		s = **(short **)rootp;
		printf("%hd ", s);
	}
}

int furtherCheck(short nNum, short num[]){
	void *root = NULL, *match;
	int isASeq = TRUE;
	short *s, i, j;
	short sum[10000], newFound[10000], nSum = 0, nNew;
	sum[nSum++] = num[0] + num[1];
	s = newShort(sum[0]);
	tsearch(s, &root, compareShort);
	for(i=2; (i<nNum) && isASeq; i++){
		match = tfind(&num[i], &root, compareShort);
		if(match){
			isASeq = FALSE;
		}
		else{
			nNew = 0;
			for(j=0; j<nSum; j++){
				s = newShort(sum[j] + num[i]);
				match = tsearch(s, &root, compareShort);
				if(*(short **)match != s) {
					free(s);
				} else{
					newFound[nNew++] = *s;
				}
			}		
		
			for(j=0; j<i; j++){
				s = newShort(num[i] + num[j]);
				match = tsearch(s, &root, compareShort);
				if(*(short **)match != s) {
					free(s);
				} else{
					newFound[nNew++] = *s;
				}
			}
			for(j=0; j<nNew; j++){
				sum[nSum++] = newFound[j];
			}
		}
	}
	#if DEBUG
	twalk(root, twalkAction);
	printf("\n");
	#endif
	tdestroy(root, free);
	
	return isASeq;
}

int main(){
	short nNum, num[MAX];
	int k = 1, i;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	while(1 == fscanf(fp, "%hd", &nNum)){
		for(i=0; i<nNum; i++){
			fscanf(fp, "%hd", num + i);
		}
		printf("Case #%d:", k++);
		for(i=0; i<nNum; i++){
			printf(" %hd", num[i]);
		}
		printf("\n");
		if(basicCheck(nNum, num) == FALSE){
			puts("This is not an A-sequence.");
		} else if(furtherCheck(nNum, num) == FALSE){
			puts("This is not an A-sequence.");
		} else{
			puts("This is an A-sequence.");
		}
	}
	return 0;
}
