#include <stdio.h>

int powmod(int base, int expn, int mod){
	int result;
	if(expn == 0) return 1;
	result = powmod(base, expn >> 1, mod); 
	result = (result * result) % mod;
	if(expn & 1) {
		result = (result * base) % mod;
	}
	return result;
}

int main(){
	int nTest;
	int base, expn, mod;

	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d %d %d", &base, &expn, &mod);
		printf("%d\n", powmod(base, expn, mod));
	}	
	
	return 0;
}