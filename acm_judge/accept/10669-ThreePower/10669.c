#include <stdio.h>
#define MAX 41

int main(){
	unsigned long long set3[MAX];
	unsigned long long k;
	int i;
	set3[0] = 1;
	for(i=1; i<MAX; i++){
		set3[i] = set3[i - 1] + (set3[ i - 1] << 1);
	}	
	while(1 == scanf("%llu", &k)){
		if(k == 0) break;
		
		k--;
		for(i=0; k>0; k = k >> 1, i++){
			if(k & 1){
				printf("%llu ", set3[i]);
			}
		}
		printf("\n");
	}
	
	
	return 0;
}