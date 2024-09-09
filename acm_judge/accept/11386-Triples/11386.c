#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5001
#define DEBUG 0

int compareLong(const void *a, const void *b){
	return *(long *)a - *(long *)b;
}

long mybsearch(long target, long *seq, long left, long right){
	long middle;
	
	while(left <= right){
		middle = (left + right) >> 1;
		if(seq[middle] == target){
			
			return middle;
			
			
		}
		else if (seq[middle] < target) left = middle + 1;
		else right = middle - 1;
	}
	return -1;
}


int main(){
	long nelem;
	long i, j, k, match, start, end, index;
	long count, target;
	long seq[MAX];
	long occr[MAX];
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	while(1 == fscanf(fp, "%ld", &nelem)){
		nelem--;
		for(i=nelem; i>=0; i--){
			fscanf(fp, "%ld", &seq[i]);
		}
		qsort(seq, nelem + 1, sizeof(long), compareLong);
		if(DEBUG){
			for(i=0; i<=nelem; i++){
				printf("%ld ", seq[i]);
			}
			printf("\n");
		}
		
		
		index = 0;
		occr[index] = 1;
		match = seq[0];
		for(i=1; i<=nelem; i++){
			if(seq[i] == match){
				occr[index] += 1;
			}
			else{
				match = seq[i];
				index++;
				occr[index] = 1;
				seq[index] = seq[i];
			}
		}
		nelem = index; 
		
		if(DEBUG){
			printf("input seq:");
			for(i=0; i<=nelem; i++){
				printf("%2ld ", seq[i]);
			}
			printf("\nnoccurence:");
			for(i=0; i<=nelem; i++){
				printf("%2ld ", occr[i]);
			}
		}		
		
		count = 0;
		for(i=0; i <= nelem; i++){
			if(occr[i] > 1){
				target = seq[i]*2;
				match = mybsearch(target, seq, i+1, nelem);
				if(match != -1){
					count += (occr[i]*(occr[i] - 1)/2)*occr[match];
				}
			}
			for(j = i + 1; j <= nelem; j++){
				target = seq[i] + seq[j];
				match = mybsearch(target, seq, j+1, nelem);
				if(match != -1){
					count += occr[i]*occr[j]*occr[match];
				}
			}
		}
		printf("%ld\n",count);
	}
	
	
	return 0;
}