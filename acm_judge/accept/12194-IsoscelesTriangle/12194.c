#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG 0
#define MAX 1001

struct Point {
	int x, y;
};

int compareLL(const void *a, const void *b){
	return *(long long *)a - *(long long *)b;
	/*
	long long x, y;
	x = *(long long *)a;
	y = *(long long *)b;
	
	if (x > y) return 1;
	else if (x < y) return -1;
	else return 0;
	*/
}

long long squareSum(int a, int b){
	long long result = a;
	long long tmp;
	result = result * a;
	tmp = (long long) b * b;
	result = result + tmp;
	return result;
}

int calucateNumberOfIsoceleByRow(int nPoint, long long side[]){
	int i, j;
	int nRepeat;
	int result = 0;
	qsort(side, nPoint, sizeof(long long), compareLL);
	for(i=0; i<nPoint; ){
		j = i + 1;
		while((j < nPoint) && (side[j] == side[i])){
			j++;
		}
		nRepeat = j - i;
		result = result + ( (nRepeat *(nRepeat - 1)) / 2);
		i = j;
	}
	return result;
}

int calculateNumerOfIsoscele(int nPoint, long long side[MAX][MAX]){
	int i;
	int result = 0;
	
	for(i=0; i<nPoint; i++){
		result += calucateNumberOfIsoceleByRow(nPoint, side[i]); 
	}
	return result;
}

int main(){
	long long side[MAX][MAX];
	struct Point point[MAX];
	int nPoint, nSide;
	int i, j, k;
	int ans;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	while(1 == fscanf(fp, "%d", &nPoint)){
		if(nPoint == 0){
			break;
		}
		 
		for(i=0; i<nPoint; i++){
			fscanf(fp, "%d %d", &point[i].x, &point[i].y);
		}
		
		for(i=0; i<nPoint; i++){
			side[i][i] = 0;
			for(j=i+1; j<nPoint; j++){
				side[i][j] = squareSum(point[i].x - point[j].x, point[i].y - point[j].y);
				side[j][i] = side[i][j];
			}
		}
		#if 0
		for(i=0; i<nPoint; i++){
			for(j=0; j<nPoint; j++){
				printf("%lld ", side[i][j]);
			}
			printf("\n");
		}
		#endif
		
		ans = calculateNumerOfIsoscele(nPoint, side);
		printf("%d\n", ans);
	}	
	
	
	return 0;
}