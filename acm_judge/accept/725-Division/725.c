#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 10
#define SWAP(a, b) { \
	(a) = (a) ^ (b); \
	(b) = (a) ^ (b); \
	(a) = (a) ^ (b); \
}

struct Record{
	char quotient;
	int up, down;
};

struct Record record[300];
short nRecord = 0;
short nSolution = 0;

int compareRecord(const void *a, const void *b){
	struct Record *x, *y;
	x = (struct Record *)a;
	y = (struct Record *)b;
	if(x->quotient != y->quotient) return x->quotient - y->quotient;
	return x->up - y->up;
}

int nextPermutation(char *src, int nChar){
	int k, anchor, ell;
	for(anchor = nChar - 2; anchor >= 0; anchor--){
		if(src[anchor] < src[anchor + 1]) break; 
	}
	if(anchor < 0){
		return EXIT_FAILURE;
	}
	ell = nChar - 1;
	while(src[ell] <= src[anchor]) ell--;
	SWAP(src[ell], src[anchor]);
	k = anchor + 1;
	ell = nChar - 1;
	while(k < ell){
		SWAP(src[k], src[ell]);
		k++;
		ell--;
	}
	return EXIT_SUCCESS;
}

void buildTable(){
	char digit[LEN + 1];
	char i;
	int state = EXIT_SUCCESS;
	int up, down;
	char sup[6], sdown[6];
	for(i=0; i<LEN; i++){
		digit[i] = i + '0';
	}
	digit[LEN] = '\0';
	while(state == EXIT_SUCCESS){
		strncpy(sup, digit, 5);
		strncpy(sdown, digit + 5, 5);
		up = atoi(sup);
		down = atoi(sdown);
		if(up % down == 0){
			record[nRecord].quotient = up / down;
			record[nRecord].up = up;
			record[nRecord].down = down;
			nRecord++;
		}
		state = nextPermutation(digit, LEN);
	}
	qsort(record, nRecord, sizeof(struct Record), compareRecord);
}

void solve(char q){
	short nSolution = 0, i;
	for(i=0; i<nRecord; i++){
		if(q == record[i].quotient){
			printf("%05d / %05d = %hhd\n", record[i].up, record[i].down, q);
			nSolution++;
		}
	}
	if(nSolution == 0){
		printf("There are no solutions for %hhd.\n", q);
	}
}

int main(){
	buildTable();
	char first = 1, q;
	while(1 == scanf("%hhd", &q)){
		if(q == 0) return 0;
		
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		solve(q);
	}	
	
	return 0;
}