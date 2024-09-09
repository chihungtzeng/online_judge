#include <stdio.h>
#define MAX 10001
#define BMOD 1000000

int main(){
	long int fac[MAX];
	int i,j;
	int input;
	fac[0] = 1;
	fac[1] = 1;
	for(i=2;i<MAX;i++){
		fac[i] = (fac[i-1] * i) % BMOD;
		while((fac[i] % 10 == 0)&&(fac[i] != 0)){
			fac[i] = fac[i]/10;
		}
	}
	
	while(1 == scanf("%d",&input)){
		printf("%5d -> %ld\n",input,fac[input]%10);
	}
	
	return 0;
}