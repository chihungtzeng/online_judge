/*TLE*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

unsigned int choose[MAX][MAX];

unsigned int rchoose(int n, int m){
	if ((n==m) || (m==0)) return 1;
	if (m == 1) return n;
	if (n < m) return 0;
	if (( n < MAX) && (m < MAX)){
		return choose[n][m];
	}
	
	return rchoose(n-1,m) + rchoose(n-1, m-1);
}

int main(){
	
	long int n, m;
	short done;
	


	memset(choose, 0, sizeof(unsigned int)*MAX*MAX);
	for(n=0; n<MAX;n++){
		choose[n][0] = 1;
		choose[n][1] = n;
		choose[n][n] = 1;
		choose[n][n-1] = n;
	}	
	
	for(n=1; n<MAX; n++){
		for(m=2; m<=n; m++){
			choose[n][m] = choose[n-1][m] + choose[n-1][m-1];
		}
	}
	done = 0;
	while(!done){
		scanf("%ld %ld",&n, &m);
		if((n==0) && (m==0)){
			done = 1;
			continue;
		}
		if(m > n-m){
			m = n - m;
		}
		if((n < MAX) && (m<MAX)){
			printf("%u\n",choose[n][m]);
		}
		else{
			printf("%u\n",rchoose(n,m));
		}
	}
	
	return 0;
}
