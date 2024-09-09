#include <stdio.h>
#define MAX 20010
#define DEBUG 0

int maxSum(int dist[], int nPoint, int *start, int *end){
	int sum = 0, max = 0;
	int s, t;
	int i;
	char flag = 0;
	for(i=1; i<nPoint; i++){
		sum += dist[i];
		if((sum > 0) && (sum == dist[i]) && (flag == 0)){
			s = i;
		}
		if((sum > max) || ((sum == max) && (*start == s))){
			max = sum;
			*start = s;
			*end = i;
		}
		
		if(sum < 0){
			sum = 0;
			flag = 0;
		}
		else if(sum == 0){
			flag = 1;
		}
	}
	return max;
}

int main(){
	int nRoute, nPoint, i, k = 1;
	int dist[MAX], start, end, max;
	FILE *fp;
	fp = (DEBUG)? fopen("in2.txt", "r") : stdin;
	fscanf(fp, "%d",&nRoute);
	while(k <= nRoute){
		fscanf(fp, "%d",&nPoint);
		for(i=1; i<nPoint; i++){
			fscanf(fp, "%d", dist + i);
		}
		max = maxSum(dist, nPoint, &start, &end);
		if(max == 0){
			printf("Route %d has no nice parts\n",k);
		}
		else{
			/*printf("The nicest part of route %d is between stops %d and %d, weight=%d\n",k, start, end+1, max);*/
			printf("The nicest part of route %d is between stops %d and %d\n",k, start, end+1);
		}
		k++;
	}
	return 0;
}