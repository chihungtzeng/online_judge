/*AC 0.404s, rank 8*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define DEBUG 0
#define MAX 100001
#define MAXK 21
#define MOD 1000000009

long **preAns;
int **pascalTriangle;
long **powerTable;
int *seq;
int nN;


void initTable(){
	int i, j, k;
	/*pascal Triangle. 
	Since k<=20, the maximum vale is C(20,10) = 184756. 
	No need for integer overflow handling.
	*/
	pascalTriangle = (int **) malloc(sizeof(int *)*MAXK);
	assert(pascalTriangle);
	for(i=0; i<MAXK; i++){
		pascalTriangle[i] = (int *) malloc(sizeof(int)*MAXK);
		assert(pascalTriangle[i]);
		memset(pascalTriangle[i], 0, sizeof(int)*MAXK);
	}
	for(i=0; i<MAXK; i++){
		pascalTriangle[i][i] = 1;
		pascalTriangle[i][0] = 1;
	}
	for(i=2; i<MAXK; i++){
		for(j=1; j<i; j++){
			pascalTriangle[i][j] = pascalTriangle[i-1][j] + pascalTriangle[i-1][j-1];
		}
	}
	/*powerTable[k][i] = i^k % MOD*/
	powerTable = (long **) malloc(sizeof(long *) * MAXK);
	assert(powerTable);	
	for(i=0;i<MAXK;i++){
		powerTable[i] = (long *) malloc(sizeof(long) * MAX);
		assert(powerTable[i]);
		memset(powerTable[i], 0, sizeof(long)*MAX); 
	}
	for(i=1; i<MAX; i++){
		powerTable[0][i] = 1;
		powerTable[1][i] = i;
	}
	for(k=2; k<MAXK; k++){
		powerTable[k][0] = 0;
		powerTable[k][1] = 1;
		for(j=2; j<MAX; j++){
			powerTable[k][j] = (powerTable[k-1][j]*j) % MOD; 
		}
	}
	/*
	for(k=0; k<=5; k++){
		printf("power of %d:",k);
		for(i=0; i<10; i++){
			printf("%ld ",powerTable[k][i]);
		}
		printf("\n");
	}
	printf("\n");
	*/
}

void prepareAns(){
	int k, a, b, i, j;

	for(i=1; i<=nN; i++){
		/*k=0*/
		preAns[0][i] = (preAns[0][i-1] + seq[i]) % MOD;
	}
	
	for(k=1; k<MAXK; k++){
		for(i=1; i<=nN; i++){
			preAns[k][i] = (preAns[k][i-1] + (seq[i]*powerTable[k][i] % MOD)) % MOD;
		}
	}
	/*
	for(k=0; k<=2; k++){
		for(i=1; i<=nN; i++){
			printf("%ld ", preAns[k][i]);
		}
		printf("\n");
	}
	*/
}

long long adjust(long long x){
	long long q;
	if(x >= 0) return x % MOD;
	q = x / MOD;
	q = q - 1;
	q = -q;
	return x + q*MOD;
}



long long findAns(int k, int a, int b){
	/*binominal theorem*/
	int i, j;
	long long ans = 0, tmp, coef;
	long long sumA2B;
	
	/*printf("k=%d a=%d b=%d\n",k, a, b);*/
	if(a > 1){
		for(j=0; j<=k; j++){
			sumA2B = preAns[j][b] - preAns[j][a-1];
			sumA2B = adjust(sumA2B);
			coef = (pascalTriangle[k][j] * powerTable[k-j][a - 1]) % MOD;
			tmp =  (coef * sumA2B) % MOD;
			if((k-j) % 2 == 1) {
				ans = ans - tmp;
			}
			else{
				ans = ans + tmp;
			}
			ans = adjust(ans);
		}
	}
	else{
		/*a == 1*/
		return preAns[k][b];
	}

	
	return ans;
}


int main(){
	int nTest, i;
	int k, a, b, q;
	long long ans;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in4.txt","r") : stdin;
	seq =	(int *) malloc(sizeof(int)*MAX);
	preAns = (long **) malloc(sizeof(long *)*MAXK);
	assert(preAns);
	for(i=0; i<MAXK; i++){
		preAns[i] = (long *) malloc(sizeof(long)*MAX);
		assert(preAns[i]);
		memset(preAns[i], 0, sizeof(long)*MAX);
	}
	initTable();
	
	
	fscanf(fp, "%d",&nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp,"%d", &nN);
		for(i=1;i<=nN;i++){
			/*seq[] indexed from 1 to nN*/
			fscanf(fp,"%d", &seq[i]);
		}
		prepareAns(); /*build up a table for handling queries*/
		/*
		for(i=1; i<=nN; i++){
			printf("%ld ",preAns[1][i]);
		}
		printf("\n");
		*/
		fscanf(fp,"%d", &q);
		
		while(q >= 1){
			long temp;
			q--;
			fscanf(fp,"%d %d %d", &k, &a, &b);
			ans = findAns(k, a, b);
			printf("%lld\n",ans);
		}
	}
	
	/*release memory*/
	for(i=0; i<MAXK; i++){
		free(pascalTriangle[i]);
		free(preAns[i]);
	}
	free(preAns);
	free(pascalTriangle);
	free(seq);
	
	return 0;
}
