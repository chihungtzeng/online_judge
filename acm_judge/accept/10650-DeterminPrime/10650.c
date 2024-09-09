#include <stdio.h>
#include <string.h>
#define MAX 32000
#define DEBUG 0

int prime[3500] = {2, 3, 5};
int nPrime;

void buildPrimeTable(){
	int t, i;
	char isPrime;
	nPrime = 3;
	t = 7;
	while(t < MAX){
		isPrime = 1;
		for(i=2; (prime[i]*prime[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 4;
		isPrime = 1;
		for(i=2; (prime[i]*prime[i] <= t) && isPrime; i++){
			if(t % prime[i] == 0) isPrime = 0;
		}
		if(isPrime) prime[nPrime++] = t;
		t += 2;
	}
}


int main(){
	int i, j, diff, left, right;
	
	int ans[1000][6], nAns = 0, count;
	short color[3500];
	FILE *fp;
	
	fp = (DEBUG)? fopen("in5.txt","r") : stdin;
	
	buildPrimeTable();
	memset(color, 0, sizeof(short)*3500);	
	
	for(i=0; i<nPrime - 2; i++){
		
		
		diff = prime[i+1] - prime[i];
		if(color[i] == diff) continue;
				
		if(prime[i+1] + diff == prime[i+2]){
			j = i + 3;
			count = 3;
			color[i] = diff;
			color[i + 1] = diff;
			color[i + 2] = diff;
			ans[nAns][1] = prime[i];
			ans[nAns][2] = prime[i+1];
			ans[nAns][3] = prime[i+2];
			while((j < nPrime) && (prime[j - 1] + diff == prime[j])){
				color[j] = diff;				
				count++;
				ans[nAns][count] = prime[j];
				j++;
			}
			ans[nAns][0] = count;
			nAns++;
		}
	}
	/*
	for(i=0; i<nAns; i++){
		count = ans[i][0];
		for(j=1; j<=count; j++){
			printf("%d ", ans[i][j]);
		}
		printf(" count=%d\n", count);
	}
	*/
	
	while(2 == fscanf(fp, "%d %d",&left, &right)){
		if((0 == left) && (0 == right)) break;
		
		if(left > right){
			left = left ^ right;
			right = left ^ right;
			left = left ^ right;
		}
		
		for(i=0; i<nAns; i++){
			count = ans[i][0];
			if( (ans[i][1] >= left) && (ans[i][count] <= right)){
				printf("%d", ans[i][1]);
				
				for(j=2; j <= count; j++){
					if(ans[i][j] <= right){
						printf(" %d", ans[i][j]);
					}
				}
				printf("\n");
			}
		}
	}
	
	return 0;
}