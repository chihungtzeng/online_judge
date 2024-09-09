#include<stdio.h>
#include <string.h>
#include <assert.h>
#define MAX 1001
#define LEN 11
#define MAXLEN 1000
#define DEBUG 0

short dictWordLen[MAX];
short nWord;
char dict[MAX][LEN];


int compareChar(const void *a, const void *b){
	char x, y;
	x = *(char *)a;
	y = *(char *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

short min(short a, short b){
	if( a < b) return a;
	else return b;
}

short max(short a, short b){
	if( a < b) return b;
	else return a;
}

short LCS(char line[], short lineLen, short wordk){
	short i, j, wordlen;
	char *s;
	s = dict[wordk];
	char t[LEN][LEN];
	wordlen = dictWordLen[wordk];
	
	t[0][0] = (line[0] == s[0])? 1 : 0;
	for(i=1; i<lineLen; i++){
		t[0][i] = (line[i] == s[0])? 1 : t[0][i-1];
	}
	for(i=1; i<wordlen; i++){
		t[i][0] = (line[0] == s[i])? 1 : t[i-1][0];
	}
	
	for(i = 1; i< wordlen; i++){
		for(j=1; j<lineLen; j++){
			if(s[i] == line[j]){
				t[i][j] = t[i-1][j-1] + 1;
			}
			else{
				t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
	}
	if(t[wordlen - 1][lineLen - 1] == min(wordlen, lineLen)){
		return 1;
	}
	else return 0;
}

int main(){
	char line[LEN];
	char *ch, pos;
	short count, i;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	nWord = 0;
	fgets(dict[nWord], LEN, fp);
	while(dict[nWord][0] != '#'){
		dictWordLen[nWord] = strlen(dict[nWord]) - 1;
		dict[nWord][dictWordLen[nWord]] = '\0';
		qsort(dict[nWord], dictWordLen[nWord], sizeof(char), compareChar);
		nWord++;
		fgets(dict[nWord], LEN, fp);
	}
	
	if(DEBUG){
		printf("read %hd words\n",nWord);
		for(i=0; i<nWord; i++){
			printf("%s, size = %hd\n", dict[i], dictWordLen[i]);
		}
	}
	fgets(line, MAXLEN, fp);
	while(line[0] != '#'){
		count = 0;
		pos = 0;
		ch = line;
		while((*ch != '\0') && (*ch != '\n')){
			if(isalpha(*ch)){
				line[pos++] = *ch;				
			}
			ch++;
		}
		line[pos] = '\0';
		qsort(line, pos, sizeof(char), compareChar);
		if(DEBUG){
			printf("%s\n",line);
		}
		
		for(i=0; i<nWord;i++){
			if(LCS(line, pos, i) == 1){
				if(DEBUG){
					printf("%s matches %s\n", line, dict[i]);
				}
				count++;
			}
		}
		printf("%hd\n",count);
		fgets(line, MAXLEN, fp);
	}
	return 0;
}