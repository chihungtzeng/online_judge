#include <stdio.h>
#include <stdlib.h>
#define NR 500

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b; 
}

int main(){
	int r[NR];
	int nTest,nR,i;
	int median,middle;
	long int dist;
	
	scanf("%d",&nTest);
	while(1 <= nTest){
		nTest--;
		
		scanf("%d",&nR);
		for(i=0;i<nR;i++){
			scanf("%d",r+i);
		}
		qsort(r,nR,sizeof(int),compareInt);
		
		middle = nR/2;
		median = r[middle];
		dist = 0;
		for(i=0;i<middle;i++){
			dist += median - r[i]; 
		}
		for(i=middle+1;i<nR;i++){
			dist += r[i] - median;
		}
		printf("%ld\n",dist);
		/*printf("median: %d\n",median);*/
	} 
	
	return 0;
}
