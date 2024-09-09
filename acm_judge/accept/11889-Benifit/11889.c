#include <stdio.h>
#define MAX 500
#define DEBUG 0


int prime[MAX] = {2, 3, 5};
int nPrime = 3;
int primeSq[MAX] = {4,9, 25};


void buildPrimeTable(){
	int t, i;
	char isPrime;
	t = 7;
	while(t < 3270){
		isPrime = 1;
		for(i=2; isPrime && (primeSq[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t*t;
			nPrime++;
		}
		t += 4;
		isPrime = 1;
		for(i=2; isPrime && (primeSq[i] <= t); i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t*t;
			nPrime++;
		}
		t += 2;
	}
}

int min(int a, int b){
	if(a < b) return a;
	else return b;
}

int max(int a, int b){
	if(a > b) return a;
	else return b;
}

int factoring(int x, int factor[], int fpow[]){
	int i;
	int nFactor = 0;	
	for(i=0; (i<nPrime) && (primeSq[i] <= x); i++){
		if(x % prime[i] == 0){
			factor[nFactor] = prime[i];
			fpow[nFactor] = 0;
			do{
				fpow[nFactor]++;
				x = x / prime[i];
			} while(x % prime[i] == 0);
			nFactor++;
		}
		
	}
	if(x > 1){
			factor[nFactor] = x;
			fpow[nFactor] = 1;
			nFactor++;
	}
	return nFactor;
}

int mypow(int n, int k){
	/*n^k*/
	int d;
	if(k<0){
		printf("shit!\n");
	}
	if(k == 0) return 1;
	if(k == 1) return n;
	d = mypow(n, k/2);
	if(k % 2 == 0) return d*d;
	else return d*d*n;
}

int findAns(int A, int C){
	int factor[2][16];
	int fpow[2][16], p;
	int nFactor[2];
	int i, j, diff; 
	int ans = 1;
	/*return the smallest B such that LCM(A, B) = C*/
	/*factoring A*/
	nFactor[0] = factoring(A, factor[0], fpow[0]);
	nFactor[1] = factoring(C, factor[1], fpow[1]);
	
	if(DEBUG){
		for(i=0; i<2; i++){
			for(j=0; j<nFactor[i]; j++){
				printf("%d(%d) ",factor[i][j], fpow[i][j]);
			}
			printf("\n");
		} 
	}
	i=0;
	j=0;
	for(i=0; i<nFactor[0]; i++){
		j=0;
		while((factor[1][j] != factor[0][i]) && (j < nFactor[1])){
			j++;
		}
		if(j == nFactor[1]) return -1;
		diff = fpow[1][j] - fpow[0][i];
		
		if(diff < 0) return -1;
		else if (diff == 0){
			/*do nothing*/
		}
		else{
			ans  = ans * mypow(factor[1][j], fpow[1][j]);
		}
		fpow[1][j] = 0;
	}
	for(j=0; j<nFactor[1]; j++){
		if(fpow[1][j] > 0){
			ans *= mypow(factor[1][j], fpow[1][j]);
		}
	}
	
	return ans;
}

int main(){
	int i, nTest;
	int A, B, C;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;	
	
	buildPrimeTable();
	
	fscanf(fp, "%d",&nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%d %d",&A, &C);
		B = findAns(A, C);
		if(B < 0){
			puts("NO SOLUTION");
		}
		else{
			printf("%d\n",B);
		}
	}
	return 0;
}