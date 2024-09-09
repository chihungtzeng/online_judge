#include <stdio.h>
#include <string.h>
#define MAX 91

int nBall, ball[MAX];
int N;
char bPossible[MAX];

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
} 

void solve(){
	int i, j;
	int result;
	memset(bPossible, 0, MAX);
	qsort(ball, nBall, sizeof(int), compareInt);

	#if 0
	for(i=0; i<nBall; i++){
		printf("%d ", ball[i]);
	}
	printf("\n");
	#endif	
	
	for(i=0; i<nBall; i++){
		for(j=0; j<=i; j++){
			bPossible[ball[i] - ball[j]] = 1;
		}
	}
	
	for(result=1, i=0; (i<=N) && result; i++){
		if(!bPossible[i]) result = 0;
	}
	
	if(result){
		printf("Y\n");
	} else {
		printf("N\n");
	}
	
}

int main(){
	
	int i;
	while(2 == scanf("%d %d", &N, &nBall)){
		if((N == 0) && (nBall == 0)) break;
		
		for(i=0; i<nBall; i++){
			scanf("%d", ball + i);
		}
		solve();
	}	
	return 0;
}