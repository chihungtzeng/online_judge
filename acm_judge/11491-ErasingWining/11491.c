#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 10001

struct Digit{
	char digit;
	int pos;
};

int compareDigit(const void *a, const void *b){
	/*increasing sequence*/
	struct Digit *x, *y;
	x = (struct Digit *)a;
	y = (struct Digit *)b;
	return y->digit - x->digit; 
}

int compareDigitByPos(const void *a, const void *b){
	/*decreasing sequence*/
	struct Digit *x, *y;
	x = (struct Digit *)a;
	y = (struct Digit *)b;
	return x->pos - y->pos; 
}

struct Digit input[LEN], ans[LEN];
int nDigit, nErase;
char line[LEN];

void solve(){
	int i, curPos;
	qsort(input, nDigit, sizeof(struct Digit), compareDigit);
	for(i=0, courPos = 0; i<nErase; curPos++){
		if(input[curPos].pos 
	}
}

int main(){
	FILE *fp = stdin;
	char *pChar;
	struct Digit *pDigit;
	int count;
	while(NULL != fgets(line, LEN, fp)){
		sscanf(line, "%d %d", &nDigit, &nErase);
		if((!nDigit) && (!nErase)) return 0;
		fgets(line, LEN, fp);
		pDigit = input;
		pChar = line;
		count = 0;
		while(*pChar != '\n'){
			pDigit->digit = *pChar;
			pDigit->pos = count;
			pDigit++;
			pChar++;
			count++;
		}
		solve();
	}
	return 0;
}

