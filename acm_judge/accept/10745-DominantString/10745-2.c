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
	short i;
	struct Record *s,*t;
	s = (struct Record *) a;
	t = (struct Record *) b;
	for(i=0; i<26; i++){
		if(s->freq[i] > t->freq[i]) return 0;
	}
	if (s->slength == t->slength) return 0;
	else return 1;
}

int compareString(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

void findCharFreq(struct Record *r){
	char i, c;
	for(i=0; i<r->slength; i++){
		c = r->string[i];
		r->freq[c - 'a'] += 1;
	}
}



int main(){
	short i = 0, j, k;	
	short nInput = 0, nFoe, nOutput;
	struct Record *input;
	struct Record *arena[MAX];
	char done;
	char output[MAX][MAXLEN];
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

	for(i=0; i<26; i++){
		nFoe = 0;
		for(j=0; j<nInput; j++){
			if( input[j].freq[i] > 0){
				arena[nFoe++] = input + j;
			}
		}
		for(j=0; j < nFoe; j++){
			for(k=0; (k < nFoe) && (arena[j]->dominated == 0); k++){
				if(isDominated(arena[j], arena[k])){
					arena[j]->dominated = 1;
				}
			}
		}
	}
	
	nOutput = 0;
	for(i=0; i<nInput; i++){
		if(input[i].dominated == 0){
			strcpy(output[nOutput], input[i].string);
			nOutput++;
		}
	}
	qsort(output, nOutput, MAXLEN, compareString);
	for(i=0; i<nOutput; i++){
		puts(output[i]);
	}
	free(input);
	
	
	return 0;
}