#include <stdio.h>
#define MAX 100001
#define DEBUG 0

int n;
int seq[MAX];
int length[MAX];
int parent[MAX];
int max;

void solve(){
	int i, j, trace = 0;
	int ans[MAX], nAns;
	char done;
	
	max = 1;
	parent[0] = -1;
	length[0] = 1;
	
	for(i=1; i<n; i++){
		done = 0;
		for(j = i - 1; (j>=0) && (!done); j--){
			if(seq[i] > seq[j]){
				parent[i] = j;
				length[i] = length[j] + 1;
				done = 1;
				if(length[i] >= max){ 
					max = length[i];
					trace = i;
				}
			}
		}
		if(!done){
			length[i] = 1;
			parent[i] = -1;
		}
	}
	printf("%d\n-\n",max);
	nAns = 0;
	while(trace >= 0){
		ans[nAns++] = seq[trace];
		trace = parent[trace];
	}
	for(i=nAns - 1; i>=0; i--){
		printf("%d\n", ans[i]);
	}
	if(DEBUG){	
		puts("--------");
		for(i=0; i<n; i++){
			printf("%d: %d parent=%d legth=%d\n", i, seq[i], parent[i], length[i]);
		}
	}
}

int main(){
	int i = 0;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	while(1 == fscanf(fp, "%d", seq + i)){
		i++;
	}
	n = i;
	solve();
	return 0;
}