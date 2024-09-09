#include <stdio.h>
#define UB 6227020800
#define LB 10000
#define NUM_FAC 14


int main(){
	char done = 0;
	int i;
	unsigned long long fac[NUM_FAC + 1];
	
	fac[0] = 1;
	i = 1;
	while(!done){
		fac[i] = i * fac[i-1];
		if(fac[i] > UB) done = 1;
		else i++;
	}
	
	
	while(1 == scanf("%d", &i)){
		if(i >= NUM_FAC) puts("Overflow!");
		else if ((i >= 8) && (i < NUM_FAC)) printf("%llu\n", fac[i]);
		else if (i >= 0) puts("Underflow!");
		else if (0 == (i % 2)) puts("Underflow!");
		else puts("Overflow!");
	}
	return 0;
}