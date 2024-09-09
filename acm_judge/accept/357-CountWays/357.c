#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
#define MAX 30001


 
int *exchange;
int unit[] = {1, 5, 10, 25, 50};

long long solve(int n, int level){
	long long result = 0;
	int used;
	int i;
	if(level == 0) return 1;
	for(used = 0; used <= n; used += unit[level]){
		result += solve(n - used, level - 1);
	}
	return result;
} 

int main(){
	int nCent;
	long long ans;
	FILE *fp = (DEBUG)? fopen("in.txt", "r") :stdin;


	
	while(1 == fscanf(fp, "%d", &nCent)){
		ans = solve(nCent, 4);;
		if(ans > 1){
			printf("There are %lld ways to produce %d cents change.\n", ans, nCent);
			
		} else {
			printf("There is only 1 way to produce %d cents change.\n", nCent);
		}
	}

	return 0;
}