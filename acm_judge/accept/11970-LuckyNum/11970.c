#include <stdio.h>
#define MAX 100

short nLucky;
int lucky[MAX];
char k = 1;
long long n;



void solve(){
	int x, sq;
	char i;
	
	nLucky = 0;
	x = 1;
	
	for(sq = 1; sq*sq < n; sq++){
		x = n - sq*sq;
		if(x % sq == 0){
			lucky[nLucky++] = x;
		}
	}  
	
	if(nLucky == 0){
		printf("Case %hhd:\n", k++);
	}
	else{
		printf("Case %hhd: %d", k++, lucky[nLucky - 1]);
		for(i=nLucky-2; i>=0; i--){
			printf(" %d", lucky[i]);
		}
		printf("\n");
	}
}

int main(){
	char nTest;
	scanf("%hhd", &nTest);
	while(nTest > 0){
		nTest--;
		scanf("%lld", &n);
		if(n == 1){
			printf("Case %hhd:\n", k++);
		}
		else{
			solve();
		}
	}
	return 0;	
}