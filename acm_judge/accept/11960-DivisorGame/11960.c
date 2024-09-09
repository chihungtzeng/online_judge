#include <stdio.h>

#define MAX 1000001

unsigned char nDivisor[MAX];
int ans[MAX];

void buildTable(){	
	int i, j;
	ans[0] = 0;
	nDivisor[0] = 0;	
	for(i=1; i<MAX; i++){
		nDivisor[i] = 1;
		ans[i] = 0; 
	}
	
	for(i=2; i<MAX;i++){
		for(j=i; j<MAX; j += i){
			++nDivisor[j];
		}
	}
	#if 0
	int max = 0, pos =0;
	for(i=1; i<MAX; i++){
		if(nDivisor[i] >= max){
			max = nDivisor[i];
			pos = i;
		}
	}
	printf("max=%d at %d\n", max, pos);
	#endif
	
	
	for(i=1; i<MAX; i++){
		if(nDivisor[i] >= nDivisor[ans[i-1]]){
			ans[i] = i;
		} else {
			ans[i] = ans[i-1];
		}
	}
}

int main(){
	int i;
	int nTest;
	buildTable();
	scanf("%d", &nTest);
	while(nTest > 0){
		nTest--;
		scanf("%d", &i);
		printf("%d\n", ans[i]);
	}
	return 0;
}