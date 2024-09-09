#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define MAX 110

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

short *newShort(short a){
	short *s;
	s = (short *) malloc(sizeof(short));
	*s = a;
	return s;
}

int isB2(short nEle, short ele[]){
	short i, j;
	void *root = NULL;
	void *match;
	short *sum;
	int result = EXIT_SUCCESS;
	
	if(0 == nEle) return EXIT_FAILURE;

	for(i= nEle - 2; i>=0; i--){
		if( (ele[i] < 1) || (ele[i] >= ele[i+1])) return EXIT_FAILURE;
	}
	
		for(i=0; (i<nEle) && (result == EXIT_SUCCESS); i++){
			for(j=i; (j<nEle) && (result == EXIT_SUCCESS); j++){
				sum = newShort(ele[i] + ele[j]);
				match = tsearch(sum, &root, compareShort);
				if(*(short **)match != sum){
					result = EXIT_FAILURE;
				}
			}
		}
	tdestroy(root, free);
	return result;
}

int main(){
	short nEle, i, k=1;
	short ele[MAX];
	while(1 == scanf("%hd", &nEle)){
		for(i=0; i<nEle; i++){
			scanf("%hd", ele + i);
		}

#if 0
	printf("***Case %hd:", k);
	for(i=0; i<nEle; i++) printf("%hd ", ele[i]);
	printf("\n");
#endif 		
		
		if(isB2(nEle, ele) == EXIT_SUCCESS){
			printf("Case #%hd: It is a B2-Sequence.\n", k++);
		} else {
			printf("Case #%hd: It is not a B2-Sequence.\n", k++);
		}
		printf("\n");
	}
	return 0;
}