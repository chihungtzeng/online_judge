#include <stdio.h>
#define MAX 10000

int main(){
	int numerator, denominator, remainder; /* the fraction is a/b */
	int quotien[MAX];
	int nQ;
	short done;

	while( 2 == scanf("%d %d", &numerator, &denominator)){
		nQ = 0;
		done = 0;
		while(!done){
			quotien[nQ++] = numerator / denominator;
			remainder = numerator % denominator;
			numerator = denominator;;
			denominator = remainder;
			if(remainder == 0){
				done = 1;
			}
		}

		if(nQ == 1){		
			printf("[%d]\n", quotien[0]);
		}
		if (nQ > 1){
			int i;
			printf("[%d;",quotien[0]);
			for(i=1; i<nQ-1; i++){
				printf("%d,",quotien[i]);
			}
			printf("%d]\n",quotien[nQ-1]);
		}
		
	}	
	
	return 0;
}