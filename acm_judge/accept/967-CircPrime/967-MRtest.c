#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1001

int powmod(int a, int m, int n){
	/*return a^m % m*/
	long int d1, d2,d3;
	
	if ( 1 == m) return (a % n);
	else{
		d1 = powmod(a, m/2, n);
		d2 = powmod(a, m-m/2, n);
		d3 = (d1*d2) % n;
		return (int)d3; 
	} 
}

int MRtest(int n){
	/* rewrite n - 1 = 2^k *m*/
	int k,m,a,b,tmp;
	int i;
	long int square;
	
	
	if ( 0 == n % 2) return 0;
	k = 0;
	tmp = n;
	while( 0 == tmp % 2){
		k++;
	}
	m = n - 1;
	for(i=0;i<k;i++){
		m = (m >> 1);
	}
	a = 2;
	b = powmod(a,m,n);
	if (( b == 1) || ( b == n -1)){
		return 1;
	} 
	for(i=1;i<k-1;i++){
		b = powmod(b, 2, n);
		if ( b == 1 ){
			return 0;
		}
		if ( b == n - 1){
			return 1;
		}
	}
	b = powmod(b,2,n);
	if ( b != n-1) return 0;
	else return 1;
}

int compareInt(const void *x, const void *y){
	int a,b;
	a= *(int *)x;
	b= *(int *)y;
	if(a>b) return 1;
	if(a<b) return -1;
	return 0;
}

int containsForbiddenDigit(int n){
	/*if n has 0,2,4,5,6,8, then it is definitely not circular prime*/
	while(n>0){
		if ((0 == (n % 10) % 2) || (5 == n % 10)){
			return 1;
		}
		n = n/10;
	}
	return 0;
}
int findNumDigit(int n){
	int count=1;
	while (n > 10){
		count++;
		n = n/10;
	}
	return count;
}
int mypow10(int d){
	if (d==1) return 10;
	else return mypow10(d/2)*mypow10(d - d/2);
}
int isCircPrime(int n, int primeList[], int nPrime){
	int nDigit;
	int i,divider;
	int *match;
	
	if(containsForbiddenDigit(n)) return 0;
	
	nDigit = findNumDigit(n);
	divider = mypow10(nDigit-1);
	
	for(i=0;i<nDigit;i++){
		n = (n%divider)* 10 + (n/divider);
		match = (int *) bsearch(&n,primeList,nPrime,sizeof(int),compareInt);
		if (match == NULL) {
			return 0;
		}
	}
	return 1;
}

int main(){
	int primeList[MAX];
	int pseudoPrimeList[MAX];
	int circPrime[100];
	int nCircPrime;
	int nPrime,nPseudoPrime;
	int left,right;	
	int i,j;
	int sqrtNum;
	int isPrime;
	int ans;
	
	/*Miller-Robin Test*/

	pseudoPrimeList[0] = 2;
	nPseudoPrime = 1; /*2 is a prime*/
	for(i=3;i<MAX;i++){
			
		if((MRtest(i))){
			pseudoPrimeList[nPseudoPrime] = i;
			nPseudoPrime++;
			
			
		}
	}
	printf("%d prime found in [2..%d] by Miller-Robin test\n",nPseudoPrime,MAX);
	
	primeList[0] = 2;
	nPrime=1;
	for(i=3;i<MAX;i++){
		
		sqrtNum = sqrt(i);
		
		isPrime = 1;
		j=0;
		while((j<sqrtNum) && (isPrime)){
			if(i % primeList[j] == 0) {
				isPrime=0;
			}
			j++;
		}
		if(isPrime){
			primeList[nPrime] = i;
			nPrime++;
			
		}
	}	
	
	printf("%d prime found in [2..%d] by sequential method\n",nPrime,MAX);
	
	/*List pseudo prime*/
	j=0;
	for(i=0;i<nPseudoPrime;i++){
		if(primeList[j] == pseudoPrimeList[i]){
			j++;
		}
		else {
			printf("pseudo prime: %d\n",pseudoPrimeList[i]);
			
		}
	}
	
	/*/
	nCircPrime = 0;
	for(i=1;i<nPrime;i++){
		if(primeList[i] > 100){
			if (isCircPrime(primeList[i],primeList,nPrime)){
				circPrime[nCircPrime] = primeList[i];
				nCircPrime++;
			}
		}
	}
	
	while(2 == scanf("%d %d",&left,&right)){
		ans = 0;
		for(i=0;i<nCircPrime;i++){
			if ((circPrime[i] >= left) && (circPrime[i] <= right)){
				ans++;
			}
		}
		if (0 == ans){
			printf("No Circular Primes.\n");
		}
		else {
			printf("%d Circular Primes.\n",ans);
		}
	}	
	*/
	return 0;
}