#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000001


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
	int circPrime[100];
	int nCircPrime;
	int nPrime;
	int left,right;	
	int i,j;
	int sqrtNum;
	int isPrime;
	int ans;
	
	/*construct prime list*/
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
		else if (1 == ans){
			printf("1 Circular Prime.\n");
		}
		else {
			printf("%d Circular Primes.\n",ans);
		}
	}	
	
	return 0;
}