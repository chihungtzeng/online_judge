#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32
#define DEBUG 0


struct ele{
	char id;
	short occr, suffixLen;
};

struct ele *newEle(char id){
	struct ele *e;
	e = (struct ele *) malloc(sizeof(struct ele));
	e->id = id;
	e->occr = 1;
	e->suffixLen = 0;
	return e;
}

short min(short a, short b){
	if (a < b) return a;
	else return b;
}

void findComb(struct ele *seq[], short len, short t, char *prefix, short startPos){
	/*seq[] : input string, len: length of input string*/
	/*We are going to generate strings of length t*/
	short i, j;
	short infixLB, infixUB; /*lower/upper bound for infix*/
	short prefixLen;
	char *newPrefix, *infix;	

	prefixLen = strlen(prefix);
	
	if((startPos == len - 1) && (seq[startPos]->occr >= t)){
		printf("%s",prefix);
		for(i = 0; i < t; i++){
			printf("%c",seq[startPos]->id);
		}
		printf("\n");
		return ;
	}
	
	if(t == seq[startPos]->suffixLen){
		printf("%s",prefix);
		for(i=startPos; i<len; i++){
			for(j=0; j<seq[i]->occr; j++){
				printf("%c",seq[i]->id);
			}
		}
		printf("\n");
		return ;
	}
	
	if(t > seq[startPos]->suffixLen){
		if(DEBUG){
			printf("suffix of length %hd is not long enough to generate a string of length %hd\n", seq[startPos]->suffixLen, t);
		}
		return ;
	}
	
	
	if(t == 0){
		printf("%s\n", prefix);
		return ;
	}
	else if ( t < 0){
		printf("cannot generate length < %hd", t);
		return;
	} 
	
	/*Now we are going to generate infix*/
	infixUB = min(t, seq[startPos]->occr);
	newPrefix = (char *) malloc(sizeof(char)*MAX);
	for(i = infixUB; (i>=0); i--){		
		strcpy(newPrefix, prefix);
		infix = (char *) malloc(sizeof(char)*(i+1));
		for(j=0; j<i; j++){
			infix[j] = seq[startPos]->id;
		}
		infix[i] = '\0';
		strcat(newPrefix, infix);
		if(t - i == 0){
			printf("%s\n", newPrefix);
		}
		else if ((t - i > 0) && (startPos + 1 < len) && (t - i <= seq[startPos + 1]->suffixLen)){
			/*the remaining seq can generate a string of length t - i*/
			findComb(seq, len, t - i, newPrefix, startPos + 1);
		}
		free(infix);
	}
	free(newPrefix);
}

int compareChar(const void *a, const void *b){
	char x, y;
	x = *(char *)a;
	y = *(char *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

int main(){
	char line[MAX];
	char *prefix;
	short t, len, i, j;
	struct ele *seq[MAX];
	FILE *fp;
	
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;
	
	while(2 == fscanf(fp, "%s %hd",line, &t)){
		len = strlen(line);
		qsort(line, len, sizeof(char), compareChar);
		
		j = 0;
		seq[0] = newEle(line[0]);
		for(i=1; i<len; i++){
			if(line[i] == seq[j]->id){
				seq[j]->occr += 1;
			}
			else {
				j++;
				seq[j] = newEle(line[i]);
			}
		}
		/*j is the index of last element*/
		len = j + 1;
		seq[j]->suffixLen = seq[j]->occr;		
		for(i = j - 1; i>=0; i--){
			seq[i]->suffixLen += seq[i]->occr + seq[i+1]->suffixLen;
		}
		if(DEBUG){
			for(i=0; i<len; i++){
				printf("char %c appear %hd times, suffixLen = %hd\n", seq[i]->id, seq[i]->occr, seq[i]->suffixLen);
			}
		}		
		
		
		prefix = (char *) malloc(sizeof(char)*MAX);
		prefix[0] = '\0';
		findComb(seq, len, t, prefix, 0);
		
		
		for(i=0; i<len; i++){
			free(seq[i]);
		}
		free(prefix);
	}
	return 0;
}