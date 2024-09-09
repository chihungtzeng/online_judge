#include <stdio.h>
#define MAX 64
#define BOUND 1000000001

int fib[MAX];
char nFib;

int buildFibTable(){
	int i;
	fib[0] = 1;
	fib[1] = 2;
	for(i=2; (i<MAX) && (fib[i-1] < BOUND); i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	nFib = i;
}

void solve(int n){
	char i, j=0;
	char output[MAX];
	i = nFib - 1;
	while(fib[i] > n) --i;
	
	while(i>=0){
		if(n >= fib[i]){
			output[j] = '1';
			n = n - fib[i];
		}
		else{
			output[j] = '0';
		}
		--i;
		++j;
	}
	output[j] = '\0';
	puts(output);
}

int main(){
	int nTest;
	int n;
	buildFibTable();
	scanf("%d", &nTest);
	while(nTest > 0){
		nTest--;
		scanf("%d", &n);
		solve(n);
	}
	return 0;
}