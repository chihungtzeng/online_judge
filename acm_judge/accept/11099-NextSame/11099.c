#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define UPPER_BOUND 2000000
#define MAX 1000000
#define NPRIME 200
#define NCANDIDATE 1000
#define DEBUG 0


int primeSq[NPRIME], prime[NPRIME];
int divisor[NPRIME];
int nPrime, nInput;
int *input;
int *ans;
void *root;

struct Query{
	int n;
	int ans;
};

struct Query *newQuery(int n){
	struct Query *q;
	q = (struct Query *) malloc(sizeof(struct Query));
	q->n = n;
	q->ans = -1;
	return q;
}

int compareQuery(const void *a, const void *b){
	struct Query *x, *y;
	x = (struct Query *) a;
	y = (struct Query *) b;
	return x->n - y->n;
}

int compareLL(const void *a, const void *b){
	return *(long long *)a - *(long long *)b;
}

long long *newLL(long long a){
	long long *n = (long long *) malloc(sizeof(a));
	*n = a;
	return n;
}

void buildPrimeTable(){
	int t;
	short i, step;
	char isPrime;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	nPrime = 3;
	for(i=0; i<3; i++){
		primeSq[i] = prime[i] * prime[i];
	}
	t = 7; 
	step = 4;
	while(t <= 1000){
		isPrime = 1;
		for(i=1; (primeSq[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime){
			prime[nPrime] = t;
			primeSq[nPrime] = t * t;
			nPrime += 1;
		}
		t += step;
		step = 6 - step;
	}
}


long long findCandidate(int bound, short nDivisor, int divisor[]){
	/*find the least product of divisor[] such that the product >= bound */
	long long *newEle;
	long long result;
	short i, j;
	int nNew = 0, nGen, nCandidate = 0;
	long long *newEleArray, *gen, *tmp, *candidate, smallest;
	void *match, *root = NULL;
	char done = 0;

	gen = (long long *) malloc(sizeof(long long)*NPRIME);
	newEleArray = (long long *) malloc(sizeof(long long)*NPRIME);	
	candidate = (long long *) malloc(sizeof(long long)*NCANDIDATE);
	
	for(i=0; (i<nDivisor) ; i++){
			newEle = newLL(divisor[i]);
			newEleArray[nNew++] = divisor[i];
			candidate[nCandidate++] = divisor[i];
			tsearch(newEle, &root, compareLL);
	}
	
	while(!done){
		nGen = 0;
		for(i=0; (i<nNew) ; i++){
			if(newEleArray[i] >= bound){
				continue;
			}
			for(j=0; (j<nDivisor) ; j++){
				newEle = newLL(newEleArray[i] * divisor[j]);		
				match = tsearch(newEle, &root, compareLL);
				if(*(long long **)match != newEle){
					free(newEle);
				} else {
					gen[nGen++] = *newEle;
					candidate[nCandidate++] = *newEle;
				}
			}
		}
		
		
		done = 1;
		for(i=0; i<nGen; i++){
			done &= (gen[i] >= bound); 
		}
		
		
		if(done){
			qsort(candidate, nCandidate, sizeof(candidate[0]), compareLL);
				
			#if 0
			printf("nCandidate=%d\n", nCandidate);
			for(i=0; i<nCandidate; i++){
				printf("%lld ", candidate[i]);
			}
			printf("\n");
			#endif
			for(i=0; i<nCandidate; i++){
				if(candidate[i] >= bound) {
					result = candidate[i];
					break;
				}
			}
		}
		else{
			tmp = gen;
			gen = newEleArray;
			newEleArray = tmp;
			nNew = nGen;
		}
	}	
	
	
	free(gen);
	free(newEleArray);
	tdestroy(root, free);
	free(candidate);
	return result;
}

void solve(int index){
	short i, nDivisor = 0;
	int tmp;
	long long candidate = 1;
	struct Query *q;
	void *match;
	if(input[index] == 1){
		ans[index] = -1;
		return ;
	}
	q = newQuery(input[index]);
	match = tsearch(q, &root, compareQuery);
	if(q != *(struct Query **) match){
		free(q);
		q = *(struct Query **) match;
		ans[index] = q->ans;
		return ;
	}	
	tmp = input[index];
	for(i=0; (i<nPrime) && (1 < tmp) ; i++){
		if(tmp % prime[i] == 0){
			divisor[nDivisor++] = prime[i];
			do {
				tmp = tmp / prime[i];
			} while(tmp % prime[i] == 0); 
		}
	}
	
	if(!nDivisor){
		candidate = (long long)input[index] * input[index];
	} else{
		if(tmp > 1){
			divisor[nDivisor++] = tmp;
		}
		tmp = divisor[0];		
		for(i=1; i<nDivisor; i++){
			tmp *= divisor[i];
		}
		candidate = tmp * findCandidate((input[index] / tmp) + 1, nDivisor, divisor);
	}
	
	if(candidate < 2000000){
		ans[index] = candidate;
		q->ans = candidate;
	} else {
		ans[index] = -1;
		q->ans = -1;
	}
}

int main(){
	int i;
	FILE *fp;
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	root = NULL;
	buildPrimeTable();
	input = (int *) calloc(sizeof(int), MAX);
	ans = (int *) calloc(sizeof(int), MAX);
	
	nInput = 0;
	while(1 == fscanf(fp, "%d", &input[nInput])){
		nInput += 1;
	}
	
	for(i=0; i<nInput; i++){
		solve(i); 
	}
	for(i=0; i<nInput; i++){
		if(ans[i] == -1){
			puts("Not Exist!");
		}
		else {
			printf("%d\n", ans[i]);
		}
	}
	free(input);
	free(ans);
	tdestroy(root, free);
	return 0;
}
