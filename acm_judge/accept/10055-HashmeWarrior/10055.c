/*AC*/
#include <stdio.h>

int main(){
	long long hashmat, opponent;
	long long diff;
	while(2 == scanf("%lld %lld", &hashmat, &opponent)){
		diff = opponent - hashmat;
		diff = (diff + (diff >> 63)) ^ (diff >> 63);
		
		printf("%lld\n", diff);
	}
	return 0;
}