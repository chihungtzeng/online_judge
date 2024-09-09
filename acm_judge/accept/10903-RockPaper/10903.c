#include <stdio.h>
#include <string.h>
#define N 128
#define K 128

int main(){
	int win[N], lose[N];
	short n, k, p1, p2, i;
	char stg1[10], stg2[10]; /*strategy*/
	double winAverage;
	char first = 1;
	short done;
	int nGame;
	
	
	done = 0;
	while(!done){
		scanf("%hd",&n);
		if(n == 0){
			done = 1;
			continue;
		}
		scanf("%hd", &k);
		
		
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		
		nGame = k*n*(n-1);
		nGame = nGame >> 1;
		memset(win, 0, sizeof(int)*N);
		memset(lose, 0, sizeof(int)*N);
		p1 = 1;
		while(nGame >= 1){
			nGame--;
			scanf("%hd %s %hd %s", &p1, stg1, &p2, stg2);
			if(p1 == 0){
				done = 1;
			}
			if((stg1[0] == 'r') && (stg2[0] == 's')){
				win[p1] += 1;
				lose[p2] += 1;
			}
			else if ((stg1[0] == 'r') && (stg2[0] == 'p')){
				lose[p1] += 1;
				win[p2] += 1;
			}
			else if ((stg1[0] == 'p') && (stg2[0] == 'r')){
				win[p1] += 1;
				lose[p2] += 1;
			}
			else if ((stg1[0] == 'p') && (stg2[0] == 's')){
				lose[p1] += 1;
				win[p2] += 1;
			}
			else if ((stg1[0] == 's') && (stg2[0] == 'p')){
				win[p1] += 1;
				lose[p2] += 1;
			}
			else if ((stg1[0] == 's') && (stg2[0] == 'r')){
				lose[p1] += 1;
				win[p2] += 1;
			}
		}
		for(i=1; i<=n; i++){
			if((lose[i] != 0) || (win[i] != 0)){
				winAverage = (double) win[i]/(win[i] + lose[i]);
				printf("%.3lf\n",winAverage);
			}
			else{
				printf("-\n");
			}
		}
	}
	 
	return 0;
}