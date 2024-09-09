#include <stdio.h>
#define MAX 12

int main(){
	unsigned char n, age[MAX], k=1, nTest, i;
	scanf("%hhu",&nTest);
	while(k <= nTest){
		scanf("%hhu",&n);
		for(i=0; i<n; i++){
			scanf("%hhu", age + i);
		}
		printf("Case %hhu: %hhu\n",k++,age[n >> 1]);
	}
	return 0;
}