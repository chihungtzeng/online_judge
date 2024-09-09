#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 1e-15
#define MAX 10010
#define DEBUG 0
#define VERBOSE 0

double ablist[MAX];
short n;

int compareDouble(const void *a, const void *b){
	double x, y;
	x = *(double *)a;
	y = *(double *)b;
	if(x < y) return -1;
	else if (x > y) return 1;
	else return 0;
}

int main(){
	short k=1;
	int ans, i, j;	
	FILE *fp;
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	while(1 == fscanf(fp, "%hd", &n)){
		if(n == 0) break;
		
		for(i=n-1; i>=0; i--){
			fscanf(fp, "%lf",&ablist[i]);
		}
		qsort(ablist, n, sizeof(double), compareDouble);
		ans = 0;
		for(i=0; i<n; i++){
			for(j=i+1; j<n; j++){
				if( (ablist[i] + ablist[j])*(1 - ablist[i]*ablist[j]) > 0){
					ans++;
				}
			}
		}
		
		printf("Case %hd: %d\n",k++, ans);
		
	}
	return 0;
}