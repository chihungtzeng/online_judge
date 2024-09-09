#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXM 205
#define YES 1
#define NO 0
#define APOS 240
#define DEBUG 0

short startMutate(short m, short seq1[], short seq2[], short source, short target, short mutate[]){
	/*source mutate into target*/
	short i;
	for(i=0; i<m; i++){
		if(seq1[i] == source){
			seq1[i] = target;
		}
		if(seq2[i] == source){
			seq2[i] = target;
		}
	}
	mutate[source] = target;
	return EXIT_SUCCESS;
} 

void printDNA(short m, short seq[]){
	short i;
	for(i=0; i<m; i++){
		if(seq[i] < APOS){
			printf("%d", seq[i]);
		}
		else {
			printf("%c", seq[i] - APOS + 'A');
		}
	}
	printf("\n");
}

short findConverge(short m, short seq1[], short seq2[], short mutate[]){
	short d1, d2;
	short target, i;
	for(i=0; i<m ;i++){
		if( (seq1[i] < APOS) && (seq2[i] < APOS)){
			/*both mutated DNA, do nothing*/ 
		}
		else if ((seq1[i] < APOS) && (seq2[i] >= APOS)){
			/*DNA1 is mutate, but DNA2 is normal*/
			startMutate(m, seq1, seq2, seq1[i], seq2[i], mutate);
		}
		else if ((seq1[i] >= APOS) && (seq2[i] < APOS)){
			/*DNA1 is normal, but DNA2 is mutatant*/
			startMutate(m, seq1, seq2, seq2[i], seq1[i], mutate);
		}
		else if ((seq1[i] >= APOS) && 
			(seq2[i] >= APOS) && 
			(seq1[i] != seq2[i])){			
			if(DEBUG) printf("fail at m=%d\n", i);
			return NO;			
		} 
	}
	if(DEBUG){
		printf("DNA evolution:\n");
		printDNA(m, seq1);
		printDNA(m, seq2);
	}
	for(i=0; i<m; i++){
		if((seq1[i] >= APOS) && (seq2[i] >= APOS) && (seq1[i] != seq2[i])){
			if(DEBUG) printf("fail at m=%d, last check, type 1\n", i);
			return NO;
		}
		if (
			((seq1[i] >= APOS) && (seq2[i] < APOS)) ||
			((seq1[i] <  APOS) && (seq2[i] >= APOS))){
			if(DEBUG) printf("fail at m=%d, last check, type 2\n", i);
			return NO;
		}
	}
	return YES;
}

int main(){
	short seq1[MAXM], seq2[MAXM];
	short mutate[MAXM];
	char s[24];
	char first = 1;
	short m, i, ans;
	
	
	while(1 == scanf("%hd",&m)){
		if(first){
			first = 0;
		}	
		else {
			printf("\n");
		}
	
		for(i=0; i<m; i++){
			scanf("%s", s);
			seq1[i] = (isalpha(s[0]))? s[0] - 'A' + APOS : atoi(s);
		}
		for(i=0; i<m; i++){
			scanf("%s", s);
			seq2[i] = (isalpha(s[0]))? s[0] - 'A' + APOS : atoi(s);
		}
		
		if(DEBUG){
			printDNA(m, seq1);
			printDNA(m, seq2);
		}		
		
		memset(mutate, 0xff, sizeof(short)*MAXM);
		
		ans = findConverge(m, seq1, seq2, mutate);
		
		if(ans == NO){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			for(i=0; i<MAXM; i++){

				if(mutate[i] >= APOS){
					printf("%d %c\n", i, mutate[i] - APOS + 'A');
				}
			}
		} 
	}
	return 0;
}