#include <stdlib.h>
#include <stdio.h>
#define MAX 25000000000000

int main(){
	long long x, y, N,xc, yc;
	long long k=0;
	FILE *fout, *fin;
	
	fin = fopen("in2.txt", "w");
	fout = fopen("out2.txt", "w");
	srand(time(NULL));
	
	
	while(k<5000){
		x = rand() % 5000000;
		y = rand() % 5000000;
		xc = x*x*x;
		yc = y*y*y;
		N = xc - yc;
		if( (N > 0) && (xc > 0) && (yc > 0) && (N <= MAX) && (yc + N == xc)){
			fprintf(fin, "%lld\n",N);
			fprintf(fout, "%lld %lld\n", x, y);
			k++;
		}
	}
	fclose(fin);
	fclose(fout);
}
