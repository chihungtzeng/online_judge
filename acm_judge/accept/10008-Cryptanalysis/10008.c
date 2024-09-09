#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32768

struct charfreq{
	char c;
	int freq;
};

int compareCharfreq(const void *a, const void *b){
	struct charfreq *x, *y;
	x = (struct charfreq *)a;
	y = (struct charfreq *)b;
	return ((y->freq - x->freq) << 5) + (x->c - y->c); 
}

int main(){
	char c;
	int nLine, nReadLine, i;
	FILE *fp;
	struct charfreq charTable[26];
	
	scanf("%d", &nLine);
	nReadLine = 0;
	memset(charTable, 0, sizeof(struct charfreq)*26);
	for(i=0; i<26; i++){
		charTable[i].c = 'A' + i;
	}
	while(1){
		c = getchar();
		if( c == '\n') {
			nReadLine++;
			if(nReadLine > nLine){
				break;
			}
		}
		else if ((c <= 'z') && (c >= 'a')){
			charTable[c - 'a'].freq += 1;
		}
		else if ((c <= 'Z') && (c >= 'A')){
			charTable[c - 'A'].freq += 1;
		}
		else if (c == EOF){
			break;
		}
	}
	qsort(charTable, 26, sizeof(struct charfreq), compareCharfreq);
	for(i=0; (i <	26) && (charTable[i].freq > 0); i++){
		printf("%c %d\n", charTable[i].c, charTable[i].freq);
	}
	
	return 0;
}