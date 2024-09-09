#include <stdio.h>
#define MAX 31622
#define RANGE 10001

int prime[MAX] = {2, 3, 5};
int nPrime = 3;
int primeSq[MAX] = {4, 9, 25};
short ans[RANGE]; 

void buildPrimeTable(){
	int t, i;
	char isPrime;
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime++] = t*t;
		}
		t+=4;
		isPrime = 1;
		for(i=2; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime++] = t*t;
		}
		t+=2;
	}
}

int isPrime(int n){
	int i;
	for(i=0; (i<nPrime) && (primeSq[i] <= n); i++){
		if (n % prime[i] == 0) return 0;
	}
	return 1;
}

int EulerFunc(int n){
	return n*n + n + 41;
}


int main(){
	int i, a, b, n, x, y;
	double prob;
	buildPrimeTable();
	for(i=0; i<RANGE; i++){
		ans[i] = isPrime(EulerFunc(i))? 1 : 0; 
	}	
	for(i=1; i<RANGE; i++){
		ans[i] += ans[i-1];
	}

	while(2 == scanf("%d %d",&a, &b)){
		n = (a == 0)? ans[b] : ans[b] - ans[a-1];
		prob = ((100.0*n) / (b - a + 1));
		printf("%.2lf\n",prob + 1e-12);
		/* 
		prob = ((10000.0*n) / (b - a + 1));
		x = (int) prob;
		prob = prob - x;
		y = x % 100;
		x = x / 100;
		if( prob >= 0.5) y++;
		printf("%d.%02d\n",x,y);
		*/
	}	
	return 0;	
}