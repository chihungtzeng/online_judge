#include <stdio.h>
#include <stdlib.h>
#define LEN 20001

short nHead, nKnight;
int head[LEN], knight[LEN];

void solve(){
	short i = 0, j = 0;
	int gold = 0;
	
	while( (i < nHead) && (j < nKnight)){
		if( head[i] <= knight[j]){
			gold += knight[j];
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	if(i == nHead){
		printf("%d\n", gold);
	}
	else{
		puts("Loowater is doomed!");
	}
}

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	short i;
	while(2 == scanf("%hd %hd", &nHead, &nKnight)){
		if( (0 == nHead) && (0 == nKnight)) return 0;
		for(i = 0; i<nHead; i++){
			scanf("%d", head + i);
		}
		for(i = 0; i<nKnight; i++){
			scanf("%d", knight + i);
		}
		qsort(head, nHead, sizeof(int), compareInt);
		qsort(knight, nKnight, sizeof(int), compareInt);
		solve();
	}
	return 0;
}
