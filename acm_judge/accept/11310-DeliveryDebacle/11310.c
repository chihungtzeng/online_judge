#include <stdio.h>
#define MAX 41

long long nWay[MAX] = {1, 1, 5};

int main(){
	short i;
	short nTest;
	for(i=3; i < MAX; i++){
		nWay[i] = nWay[i-1] + 4*nWay[i-2] + 2*nWay[i-3];
	}
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd", &i);
		printf("%lld\n",nWay[i]);
	}
	return 0;
}