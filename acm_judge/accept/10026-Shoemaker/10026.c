#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

struct Job{
	short sn;
	
	double ratio; 
};

int compareJob(const void *a, const void *b){
	struct Job *x, *y;
	x = (struct Job *) a;
	y = (struct Job *) b;
	if(x->ratio < y->ratio) return -1;
	else if (x->ratio > y->ratio) return 1;
	else return x->sn - y->sn;
}

int main(){
	short nJob, nTest;	
	short i, sn, firstCase=1;
	struct Job job[MAX];
	long long ftime, fine;
	
	
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd",&nJob);
		
		sn = 1;
		for(i=0; i<nJob; i++){

			scanf("%lld %lld", &ftime, &fine);
			job[i].sn = sn;
			sn++;
			job[i].ratio = (double) ftime / fine;
		}
		qsort(job, nJob, sizeof(struct Job), compareJob);
		if(firstCase){
			firstCase = 0;
		}
		else{
			puts("");
		}
		printf("%hd", job[0].sn);
		for(i=1; i<nJob; i++){
			printf(" %hd", job[i].sn);
		}
		printf("\n");
	}
	return 0;
}