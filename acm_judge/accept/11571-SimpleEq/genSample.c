#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 6000000000000000000
#define SAMPLE 2500

int testSample(long long A, long long B, long long C){
	if(A <= 0) return 0;
	if(A > MAX) return 0;
	if(B > MAX) return 0;
	if(B <= 0) return 0;
	if(C <= 0) return 0;
	if(C > MAX) return 0;
	return 1; 
} 

int compareLLong(const void *a, const void *b){
	long long x, y;
	x = *(long long *)a;
	y = *(long long *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}


int main(){
	long long x, y, z;
	long long A, B, C;
	long long sq;
	long long offset = RAND_MAX / 2;
	long long root[3];
	int i, j;
	FILE *input, *output;
	
	input = fopen("in6.txt", "w");
	output = fopen("out6.txt", "w");
	int count = 0;
	srand(time(NULL));
	fprintf(input, "%d\n",  SAMPLE);
	
	
	sq = sqrtl(MAX);
	for(i=-20; i<=20; i++){
		for(j=-20; j<=20; j++){
			root[0] = i;
			root[1] = j;
			if((i==0) || (j == 0) || (i == j)) continue;
			
			root[2] = sq - i - j;
			x = root[0];
			y = root[1];
			z = root[2];
			A = x + y + z;
			B = x*y*z;
			C = x*x + y*y + z*z;
			if(testSample(A, B, C) == 0) continue;
			if(B % root[0] != 0) continue;
			if(B % root[1] != 0) continue;
			if(B % root[2] != 0) continue;
			qsort(root, 3, sizeof(long long), compareLLong);
			fprintf(input, "%lld %lld %lld\n", A, B, C);
			fprintf(output, "%lld %lld %lld\n", root[0], root[1], root[2]);
			count++;
		}
	}

	while(count < SAMPLE){
		x = offset - rand();
		y = offset - rand();
		z = offset - rand();
		A = x + y + z;
		B = x*y*z;
		C = x*x + y*y + z*z;
		if(testSample(A, B, C) == 0) continue;
		
		
		if(B % x != 0) continue;
		if(B % y != 0) continue;
		if(B % z != 0) continue;
		root[0] = x;
		root[1] = y;
		root[2] = z;
		qsort(root, 3, sizeof(long long), compareLLong);

		fprintf(input, "%lld %lld %lld\n", A, B, C);
		fprintf(output, "%lld %lld %lld\n", root[0], root[1], root[2]);
		count++;
	}
	fclose(input);
	fclose(output);
}