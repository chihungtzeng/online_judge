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

short mybsearch(double target){
	short left, right, middle;
	double tmp;
	left = 0;
	right = n - 1;
	
	while(left <= right){
		middle = (left + right) >> 1;
		if( fabs(target - ablist[middle]) < EPSILON){
			while( (middle + 1 < n) && (fabs(target - ablist[middle + 1]) < EPSILON)){
				middle++;
			} 
		 	return middle;
		}
		else if (target > ablist[middle]) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right) >> 1;
} 

int findMatch(double a){	
	short x, y;
	if(a == 0){
		return n - mybsearch(EPSILON) - 1;
	}
	else if (a < 0){
		x = mybsearch(-a);
		/*
		while((x<n) && (ablist[x] < -a)){
			x++;
		} 
		*/
		x = n - x - 1;
		y = mybsearch(1/a);
		while( (y >= 0) && (ablist[y] > 1/a)){
			y--;
		} 
		if(VERBOSE){
			printf("query: %lf, >=-q: %d itmes, < 1/q: %d itmes\n",a, x, y);
		}
		if(a < 1/a){
			return x + y;
		}
		else {
			return x + y + 1;
		}
	}
	else if (a > 0){
		x = mybsearch(-a);  		
		y = mybsearch(1/a);
		if(VERBOSE){
			printf("query: %lf, <= -q: %d itmes, <= 1/q: %d itmes\n",a, x, y);
		}
		if(a < 1){
			return y - x - 1;
		}
		else{
			return y - x;
		}
	}
}

int findAns(){
	short i;
	int ans = 0, tmpAns;
	
	for(i = 0; i<n; i++){
		
		tmpAns = findMatch(ablist[i]);
		ans += tmpAns;
		if(VERBOSE){
			printf("found %d matches for target %lf\n\n", tmpAns, ablist[i]);
		}
	}
	return ans >> 1;
}

int main(){
	short i, k=1;
	int ans;	
	FILE *fp;
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	while(1 == fscanf(fp, "%hd", &n)){
		if(n == 0) break;
		
		for(i=n-1; i>=0; i--){
			fscanf(fp, "%lf",&ablist[i]);
		}
		qsort(ablist, n, sizeof(double), compareDouble);
		
		/*
		for(i=0; i<n; i++){
			printf("%lf ", ablist[i]);
		}
		printf("\n");
		printf("%lf is at %d\n", -3.0, mybsearch(-3.0));
				
		for(i=0; i<n; i++){
			printf("%lf is at %d\n", ablist[i], mybsearch(ablist[i]));
		}
		*/
		
		ans = findAns();
		printf("Case %hd: %d\n",k++, ans);
		
	}
	return 0;
}