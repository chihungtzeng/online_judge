#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100000

int main(){
	long long r1, r2, r;
	int i;
	srand(time(NULL));
	printf("%d\n", MAX);
	for(i=0; i<MAX; i++){
		/*
		r1 = rand();
		r2 = rand();
		r = r1 *r2;
		*/
		r = i;
		printf("%lld\n", r);
	}
}
