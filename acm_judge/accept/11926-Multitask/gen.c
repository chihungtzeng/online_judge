#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int main(){
	int nRegular, nRepeat;
	int i;
		int start, end, interval;
	srand(time(NULL));
	nRegular = (rand() % 50) + 40;
	nRepeat = (rand() % 50) + 40;
	printf("%d %d\n", nRegular, nRepeat);
	for(i=nRegular; i>=0; i--){
		start = rand() % MAX;
		interval = rand() % MAX;
		printf("%d %d\n", start, interval);
	}
	for(i=nRepeat; i>=0; i--){
		start = rand() % MAX;
		end = start + rand()%MAX;
		interval = rand() % MAX;
		printf("%d %d %d\n", start, end, interval);
	}
	printf("0 0\n");
}
