#include <stdio.h>
#include <stdlib.h>
#define LEN 10001
#define A 0
#define B 1

int compareInt(const void *a, const void *b){
	int x, y;
	x = *(int *)a;
	y = *(int *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

void solve(short nEle[2], int seq[2][LEN]){
	short i, j;
	int nCommon = 0;
	qsort(seq[0], nEle[0], sizeof(seq[0][0]), compareInt);
	qsort(seq[1], nEle[1], sizeof(seq[1][0]), compareInt);
	#if 0
	for(i=0; i<nEle[0]; i++){
		printf("%d ", seq[0][i]);
	}
	printf("\n");
	for(i=0; i<nEle[1]; i++){
		printf("%d ", seq[1][i]);
	}
	printf("\n");
	#endif
	i = 0;
	j = 0;

	while((i<nEle[0]) && (j<nEle[1])){
		if(seq[0][i] == seq[1][j]){
			++i;
			++j;
			++nCommon;
		} else if (seq[0][i] < seq[1][j]){
			++i;

		} else{
			++j;
			
		}
	}
	printf("%d\n", nEle[0] + nEle[1] - (nCommon << 1));
}

int main(){
	short nTest, i;
	short nEle[2];
	FILE *fp = stdin;
	int seq[2][LEN];

	fscanf(fp, "%hd", &nTest);
	while(nTest > 0){
		nTest--;
		fscanf(fp, "%hd %hd", nEle, nEle + 1);
		for(i=nEle[0] - 1; i >= 0; --i){
			fscanf(fp, "%d", &seq[0][i]);
		}
		for(i=nEle[1] - 1; i >= 0; --i){
			fscanf(fp, "%d", &seq[1][i]);
		}
		solve(nEle, seq);
	}
	
	return 0;
}