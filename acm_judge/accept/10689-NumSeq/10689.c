#include <stdio.h>
#define DEBUG 0
#define MOD 10000

int mod[5] = {1, 10, 100, 1000, 10000};
int fib[32][2][2];

void calcFibTable(){
	int n=0, m;
	int tmp[2][2];
	char i, j, k,pre;
	
	/*
	fib[0][0][0] = 1;
	fib[0][0][1] = 0;
	fib[0][1][0] = 0;
	fib[0][1][1] = 1;
	fib[1][0][0] = 0;
	fib[1][0][1] = 1;
	fib[1][1][0] = 1;
	fib[1][1][1] = 1;
	*/
	fib[0][0][0] = 0;
	fib[0][0][1] = 1;
	fib[0][1][0] = 1;
	fib[0][1][1] = 1;
	while( n < 30 ){
		pre = n;
		n++;
		for(i=0; i<2; i++){
			for(j=0; j<2; j++){
				tmp[i][j] = 0;
				for(k=0; k<2; k++){
					tmp[i][j] += fib[pre][i][k] * fib[pre][k][j];
				}
			}
		}
		for(i=0; i<2; i++){
			for(j=0;j<2; j++){
				fib[n][i][j] = tmp[i][j] % MOD;
			}
		}
		if(DEBUG){
			printf("n=2^%d\n", n);
			for(i=0; i<2; i++){
				for(j=0;j<2; j++){
					printf("%d ",fib[n][i][j]);
				}
				printf("\n");
			}
		}
	}
}

int findAns(char a, char b, long n, char m){
	/*int fib[2][2] = {{0,1},{1,1}};*/
	int ans[2][2] = {{1, 0}, {0, 1}};
	int t[2][2];
	int M = mod[m];
	
	int i, j, k, p=0;
	
	if(n == 0) return a;
	if(n == 1) return b;
	
	while( n > 0){
		if(n & 1){
			for(i=0;i<2; i++){
				for(j=0;j<2; j++){
					t[i][j] = 0;
					for(k=0; k<2; k++){
						t[i][j] += fib[p][i][k]*ans[k][j];
					}
				}
			} 
			for(i=0;i<2;i++){
				for(j=0;j<2;j++){
					ans[i][j] = t[i][j] % M;
				}
			}
		}
		p++;
		n = n >> 1;
	}
	if(DEBUG){
		printf("k=lg2(n) = %d\n",k);
		for(i=0; i<2; i++){
			for(j=0; j<2; j++){
				printf("%d ", ans[i][j]);; 
			}
			printf("\n");
		}
		printf("\n");
	}
	return (ans[0][0]*a + ans[0][1]*b) % M;
}

int main(){	
	short nTest;
	char a, b, m;
	long n;
	int ans;
	calcFibTable();
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hhd %hhd %ld %hhd",&a, &b, &n, &m);
		ans = findAns(a, b, n, m);
		printf("%d\n",ans);
	}
	return 0;
}