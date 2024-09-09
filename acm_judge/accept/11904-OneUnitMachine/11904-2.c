/*AC 0.688s*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1024
#define MOD 1000000007
#define MODMINUS2  1000000005
#define DEBUG 0
#define LEN 1000000

long long *invMod; /*i*invMod[i] = 1 (mod MOD)*/
long long *fac; /*n! mod MOD*/
long long *invFacMod; /* 1/n! mod MOD*/

long long powmod(long long x, long long y){
/*return x^y % MOD */
	long long d;
	
	if(y == 1) return x;
	d = powmod(x, y/2);
	d = d*d % MOD;
	if(y % 2 == 0) return d;
	else return d*x % MOD;
}


void calcTable(){
	long long i;
	long long result = 1, rFac = 1;
	

	invMod = (long long *) malloc(sizeof(long long)*LEN);
	fac = (long long *) malloc(sizeof(long long)*LEN);
	invFacMod = (long long *) malloc(sizeof(long long)*LEN);	
	
	invMod[0] = 0;
	invMod[1] = 1;
	for(i=2; i<LEN; i++){
		invMod[i] = powmod(i, MODMINUS2);
	}
	
	fac[0] = 1;
	invMod[0] = 1;
	fac[1] = 1;
	invFacMod[1] = 1;
	for(i=2; i<LEN; i++){
		rFac = i*fac[i-1];
		rFac = (rFac < MOD)? rFac : rFac % MOD;
		fac[i] = rFac;
		
		result = result*invMod[i];
		
		result = (result < MOD)? result : result % MOD;
		invFacMod[i] = result;
	}
	
}


long long getCoef(long long m, long long n){
	long long result;
	if( (n == 1) || (n == m - 1)) return m;
	if( (n == 0) || (n == m)) return 1;
	
	result = (fac[m] * invFacMod[n]) % MOD;
	result = (result * invFacMod[m - n]) % MOD;
	if(DEBUG){
		printf("getCoef(%lld %lld) = %lld\n", m, n, result);
	}
	return result;
}

long long findAns(long long nJob, long long job[]){
	long long result = 1;
	long long i;
	long long nPos, nObj, sum;
	
	sum = job[0];
	
	for(i=1; i<nJob; i++){
		result *= getCoef(sum + job[i] - 1, job[i] - 1);
		sum += job[i];
		result = result % MOD;
	}
	
	
	return result;
}

int main(){
	long long nTest, k = 1;
	long long nJob, i;
	long long job[MAX], ans;

	calcTable();
	if(DEBUG){
		for(i=0; i<10;i++){
			printf("i=%lld fac[i] = %lld invMod[i]=%lld invFacMod[i]=%lld\n",i, fac[i], invMod[i], invFacMod[i]);
		}	
		printf("MOD = %d\n", MOD);
	}
	

	scanf("%lld",&nTest);
	while(k <= nTest){
		scanf("%lld", &nJob);
		for(i=0; i<nJob; i++){
			scanf("%lld", job+i);
		}
		ans = findAns(nJob, job);
		printf("Case %lld: %lld\n", k, ans);
		k++;
	}

	free(invMod);
	free(invFacMod);
	free(fac);
	return 0;
}