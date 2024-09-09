#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 101
#define MAXM 101
#define LEN 32
#define DEBUG 0

short nLetter, nDictWord, nEncWord;
char encWord[MAXN][LEN];
char dictWord[MAXM][LEN];
char seed[LEN];
char letter[LEN];
char ans[LEN];

void output(){
	short i;
	for(i=1; i<=nLetter; i++){
		printf("%c", isalpha(ans[i])? ans[i] : '?');
	}
	printf("\n");
}

int isMatch(const char letter[], char dictWordIndex, char encWordIndex){
	char i, j;
	if(encWord[encWordIndex][0] != dictWord[dictWordIndex][0]) return EXIT_FAILURE;
	
	for(i=1; i<=encWord[encWordIndex][0]; i++){
		j = encWord[encWordIndex][i];
		if(letter[j] != 0){
			if( dictWord[dictWordIndex][i] != letter[j]){
				return EXIT_FAILURE;
			}
		}
	}
	return EXIT_SUCCESS;
}

int isPuzzleSovled(const char letter[]){
	char i;
	for(i=1; i<=nLetter; i++){
		if(letter[i] == 0) return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int solve(const char letter[], const char dictWordUsed[], char pos){
	char localLetter[LEN];
	char localDictWordUsed[MAXN];
	short i, j, k;
	int state;	
	
	if(isPuzzleSovled(letter) == EXIT_SUCCESS){
		memcpy(ans, letter, LEN);
		return EXIT_SUCCESS;
	}
	if(pos >= nEncWord) return EXIT_FAILURE; 

	memcpy(localLetter, letter, LEN);
	memcpy(localDictWordUsed, dictWordUsed, MAXN);
	for(i=0; i<nDictWord; i++){
		if( (dictWordUsed[i] == 0) && (EXIT_SUCCESS == isMatch(localLetter, i, pos))){
			localDictWordUsed[i] = 1;
			if(DEBUG){
				printf("enc Word %hhd matches %s\n", pos, &dictWord[i][1]);
			}
			for(j=1; j<=encWord[pos][0]; j++){
				k = encWord[pos][j];
				localLetter[k] = dictWord[i][j];
			}
			state = solve(localLetter, localDictWordUsed, pos + 1);
			if(state == EXIT_SUCCESS) return state;
			else{
				memcpy(localLetter, letter, LEN);
				memcpy(localDictWordUsed, dictWordUsed , MAXN);
			}
		}
	}
	return EXIT_FAILURE;
}

int main(){
	short i, j;
	char nTest, count, done, c;
	int state;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;	
	
	fscanf(fp, "%hhd", &nTest);
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%hd %hd",&nLetter, &nEncWord);
		memset(letter, 0, LEN);
		memset(ans, 0, LEN);
		for(i=0; i<nEncWord; i++){
			count = 0;
			done = 0;
			while(!done){
				fscanf(fp, "%hhd", &c);
				if(c == 0){
					done = 1;
				}
				else{
					count++;
					encWord[i][count] = c;
				}
			}
			encWord[i][0] = count;
		}
		fscanf(fp, "%s",seed + 1);
		seed[0] = strlen(seed+1);
		done = 0;
		nDictWord = 0;
		while(!done){
			fscanf(fp, "%s", &(dictWord[nDictWord][1]));
			dictWord[nDictWord][0] = strlen( &(dictWord[nDictWord][1]));
			if(dictWord[nDictWord][1] == '*') done = 1;
			else nDictWord++;
		}
		
		if(DEBUG){
			for(i=0; i<nEncWord; i++){
				for(j=1; j <= encWord[i][0]; j++){
					printf("%hhd ",encWord[i][j]);
				} 
				printf("\n");
			}
			for(i=0; i<nDictWord; i++){
				puts(&dictWord[i][1]);
			}
		}
		for(i=1; i<=encWord[0][0]; i++){
			j = encWord[0][i];
			letter[j] = seed[i];
		}
		
		char dictWordUsed[MAXN];
		memset(dictWordUsed, 0, MAXN);
		state = solve(letter, dictWordUsed, 1);
		if(state == EXIT_FAILURE){
			puts("No solution found");
		}
		
		output();
	}	
	
	return 0;
}


