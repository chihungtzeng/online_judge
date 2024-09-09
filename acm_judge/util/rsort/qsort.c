#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 30000

int compareInt(const void *a, const void *b){
	return *(unsigned int *)a - *(unsigned int *)b;
}


int main(){
	int i,inc,nNum;
	unsigned int *r;
	unsigned int input;
	struct timespec st,et;
	long int elapse;
	FILE *fp;
	
	fp = fopen("num.txt","r");
	fscanf(fp,"%d",&nNum);	

	
	r = (int *) malloc(sizeof(unsigned int)*nNum);
	
	
	for(i=0;i<nNum;i++){
		fscanf(fp,"%d",r+i);
	}


	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&st);	
	qsort(r,nNum,sizeof(unsigned int),compareInt);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&et);
	elapse = (et.tv_nsec >= st.tv_nsec)?
		et.tv_nsec - st.tv_nsec : 
		1000000000+et.tv_nsec-st.tv_nsec;

	printf("qsort takes %ld and 0.%ld mini seconds\n",et.tv_sec - st.tv_sec, elapse/1000000);
	


	inc=1;
	for(i=0;i<nNum-1;i++){
		if(r[i] > r[i+1]){
			inc = 0;
		}
	}
	if(inc){
		printf("Quick Sort Succ!\n");
	}	
	else{
		printf("Shit!\n");
	}
	free(r);
	exit(0);
}