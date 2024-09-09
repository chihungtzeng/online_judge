#include <stdio.h>
#define MAX 10001

int main(){
	short logtable[MAX];
	short i, pow2, p;
	short k, nTest;
	p = 1;
	pow2 = 2;
	logtable[1] = 0;
	for(i=2; i<MAX; i++){
		if(pow2 > i){
			logtable[i] = p;
		}
		else if (pow2 == i){
			logtable[i] = p;
			p++;
			pow2 = pow2 << 1;
		}
		else{
			p++;
			pow2 = pow2 << 1;
			logtable[i] = p;
		}
	}

	k = 1;
	while(1 == scanf("%hd", &i)){
		if(i < 0){
			break;
		}
		printf("Case %d: %d\n",k++, logtable[i]);
	}
	return 0;
}