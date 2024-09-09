#include <stdio.h>
#include <stdlib.h>
#define NR 500

void rsort(unsigned int *base, int nelem, int bitpos){
	unsigned int pivot;
	int i,j,k;
	
	if ((bitpos < 0)||(nelem <= 1)) return ;
	
	pivot = (1 << bitpos);
	i = 0;
	j = nelem - 1;
	while(i < j){
		while( (i < nelem ) && ((base[i] & pivot)==0) ){
			i++;
		}
		while( (j>0) && ((base[j] & pivot) > 0)){
			j--;
		}
		if(i < j){
			base[i] = base[i] ^ base[j];
			base[j] = base[i] ^ base[j];
			base[i] = base[i] ^ base[j];
		}
	}

	rsort(base,i,bitpos-1);
	rsort(base+i,nelem-i,bitpos-1); 
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
		rsort(r,nR,14);
		
		middle = nR >> 1;
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
