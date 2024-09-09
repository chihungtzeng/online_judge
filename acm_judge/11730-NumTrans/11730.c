#include <stdio.h>
#define MAX 1001
#define INF MAX
#define DEBUG 0

int prime[MAX];
int nPrime;

void buildPrimeTable(){
	int i, j;
	char bPrime[MAX];
	for(i=0; i<MAX;i++){
		bPrime[i] = 1;
	}	
	
	bPrime[2] = 1;
	for(i=2; i<MAX;i++){
		if(bPrime[i]){
			for(j=i<<1; j<MAX; j+=i){
				bPrime[j] = 0;
			}
		}
	}
	
	nPrime = 0;
	for(i=2; i<MAX; i++){
		if(bPrime[i]){
			prime[nPrime++] = i;
		}
	}
	#if 0
	for(i=0; i<nPrime; i++){
		printf("%d ", prime[i]);
	}
	printf("\n");
	#endif
}

int calcPrimeFactor(int primeFactor[], int S){
	int i;
	int nPrimeFactor;
	for(i=0, nPrimeFactor = 0; (i<nPrime) && (prime[i]*prime[i] < S); i++){
		if(S % prime[i] == 0){
			primeFactor[nPrimeFactor++] = prime[i];
			primeFactor[nPrimeFactor++] = S / prime[i];
			while(S % prime[i] == 0){
				S = S / prime[i];
			}
		}
	}
	return nPrimeFactor;
}


int solve(int S, int T){
	int ans, i;
	int nPrimeFactor;
	int primeFactor[MAX];
	int nStep;
	int best = INF;
	
	if(S == T) return 0;
	if(S > T) return INF;	
	
	nPrimeFactor = calcPrimeFactor(primeFactor, S);
	for(i=0; i<nPrimeFactor; i++){
		if(primeFactor[i] + S <= T){
			
			nStep = 1 + solve(S + primeFactor[i], T);
			#if DEBUG
			printf("S: %d -> %d, nStep=%d\n", S, S + primeFactor[i], nStep);
			#endif
			if(nStep < best){
				best = nStep;
			
			}
		}
	}
	
	return best;
}

int main(){
	int S, T, k = 1, ans;
	FILE *fp;
	fp = (DEBUG)? fopen("in4.txt", "r") : stdin;
	buildPrimeTable();
	while(2 == fscanf(fp, "%d %d", &S, &T)){
		if(!(S | T)){
			break;
		}
		ans = solve(S, T);
		if(ans >= INF) ans = -1;
		printf("Case %d: %d\n", k++, ans);
	}		
	return 0;
}