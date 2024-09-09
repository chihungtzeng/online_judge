#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 11
#define MAX 15001
#define DEBUG 0

struct Record{
	char string[MAXLEN];
	char slength;
	char freq[26];
	char dominated; 
};

int compareChar(const void *a, const void *b){
	return *(char *)a - *(char *)b;
}

int isDominated(const void *a, const void *b){
	/*a[] and b[] are arrays of the occurence of chars
		if a[] is dominated by b[] return 1, else return 0
	*/
	short i, slen=0, tlen=0;
	char *s,*t;
	s = (char *) a;
	t = (char *) b;
	for(i=0; i<26; i++){
		if(s[i] > t[i]) return 0;
		slen += s[i];
		tlen += t[i];
	}
	if (slen == tlen) return 0;
	else return 1;
}


int compareRecord(const void *a, const void *b){
	struct Record *s, *t;
	s = (struct Record *)a;
	t = (struct Record *)b;
	return strcmp(s->string, t->string);
}

int compareRecordByDomination(const void *a, const void *b){
	struct Record *s, *t;
	s = (struct Record *)a;
	t = (struct Record *)b;
	if(isDominated(s->freq, t->freq)){
		/*s is domiated*/
		s->dominated = 1;
		return -1;
	}
	else if (isDominated(t->freq, s->freq)){
		t->dominated = 1;
		return 1;
	}
	else return 0;
}

void findCharFreq(struct Record *r){
	char i, c;
	for(i=0; i<r->slength; i++){
		c = r->string[i];
		r->freq[c - 'a'] += 1;
	}
}



int main(){
	short i = 0, j;	
	short nInput = 0, nDominator;
	struct Record *input;
	
	char done;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	input = (struct Record *) malloc(sizeof(struct Record)*MAX);
	
	memset(input, 0, sizeof(struct Record)*MAX);	
	
	while(1 == fscanf(fp, "%s", input[i].string) ){
		input[i].slength = strlen(input[i].string);
		i++;
	}
	nInput = i;
	for(i=0; i<nInput; i++){
		findCharFreq(&input[i]);
	}
	qsort(input, nInput, sizeof(struct Record), compareRecord);
	for(i=0; i<nInput; i++){
		for(j=0; j<nInput; j++){
			if(isDominated(input[i].freq, input[j].freq)){
				input[i].dominated = 1;
			}
		}
	}
	for(i=0; i<nInput; i++){
		if(input[i].dominated == 0){
			puts(input[i].string);
		}
	}
	free(input);
	
	
	return 0;
}