#include <stdio.h>

int main(){
	short nTest, k=1;
	long long n, up, down;

	scanf("%hd", &nTest);	
	while(nTest){
		nTest--;
		scanf("%lld", &n);
		up = n*n - n;
		down = 4;
		while((!(up & 1)) && (down > 1)){
			up >>= 1;
			down >>= 1; 
		}
		if(down > 1){
			printf("Case %hd: %lld/%lld\n", k++, up, down);
		} else{
			printf("Case %hd: %lld\n", k++, up);
		}
	}
	
	return 0;
}