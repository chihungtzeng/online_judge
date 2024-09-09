#include <stdio.h>
#include <stdlib.h>
#define MAX 2048

short station[MAX];
short nStation;

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int findAns(){
	short i;
	for(i=1; i<nStation; i++){
		if(station[i] - station[i-1] > 200) return EXIT_FAILURE;
	}
	if( 1422 - station[nStation - 1] > 100) return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

int main(){
	short i;
	int state;
	while(1 == scanf("%hd", &nStation)){
		if(nStation == 0) return 0;
		for(i=0; i<nStation; i++){
			scanf("%hd", station + i);
		}
		qsort(station, nStation, sizeof(short), compareShort);
		if (findAns() == EXIT_SUCCESS){
			puts("POSSIBLE");
		}
		else{
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}