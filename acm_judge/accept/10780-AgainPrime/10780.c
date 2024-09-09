#include <stdio.h>

int prime[70] = {2, 3, 5};
int nPrime;

void initPrimeTable(){
	int t, i;
	char isPrime;
	t = 7;
	nPrime = 3;
	while(t <= 70){
		isPrime = 1;
		for(i=2; (prime[i]*prime[i] <= t) && isPrime; i++){
			if( t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 4;
		isPrime = 1;
		for(i=2; (prime[i]*prime[i] <= t) && isPrime; i++){
			if( t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 2;
	}
}

int findAns(int m, int n){
	int factorM[70][2];
	int nFactorM = 0;
	int tmp, count, i, d;	
	int ans=1000000;
	
	tmp = m;
	for(i=0; (i < nPrime) && (prime[i]*prime[i] <= tmp); i++){
		if(tmp % prime[i]  == 0){
			factorM[nFactorM][0] = prime[i];
			factorM[nFactorM][1] = 0;
			do{
				factorM[nFactorM][1]++;
				tmp = tmp / prime[i];
			} while(tmp % prime[i] == 0);
			nFactorM++;
		}
	} 
	if(tmp > 1){
		factorM[nFactorM][0] = tmp;
		factorM[nFactorM][1] = 1;
		nFactorM++;
	}
	for(i=0; i<nFactorM; i++){
		d = factorM[i][0];
		count = 0;
		while( d <= n){
			count = count + n/d ;
			d = d*factorM[i][0];
		}
		/*printf("factor: %d count:%d for %d!\n",factorM[i][0], count, n);*/
		if( count / factorM[i][1] < ans){
			ans = count / factorM[i][1];
		}
	}
	return ans;
}

int main(){
	int n, m, ans;
	int nTest, k = 1;
	initPrimeTable();
	scanf("%d",&nTest);
	while(nTest >= k){
		scanf("%d %d",&m, &n);
		if( (n == 1) ){
			printf("Case %d:\nImpossible to divide\n",k++);
		}
		else{
			ans = findAns(m, n);
			if(ans > 0)	{
				printf("Case %d:\n%d\n",k++,ans);
			}
			else{
				printf("Case %d:\nImpossible to divide\n",k++);
			}
		}
	}
	return 0;
}