#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128
#define LEN 32
#define FAIL 32

short len;

short sMatch(char *eWord, char *plain){
	short key, i;

	if(strlen(eWord) != len) return FAIL;
	
	key = (eWord[0] - plain[0] + 26) % 26;
	for(i=1; i<len;i++){
		if( (eWord[i] - plain[i] + 26) % 26 != key){
			return FAIL;
		}
	}
	return key;
}

int compareShort(const void *a, const void *b){
	char x, y;
	x = *(short *) a;
	y = *(short *) b;
	if (x < y) return -1;
	else if (x > y) return 1;
	else return 0;
}

int main(){
	short nTest, i;
	char line[MAX];
	char plain[LEN];
	char *tok, done;
	FILE *fp;
	short key[LEN], result, keyCount;
	
	fp = stdin;
		
	fgets(line, MAX, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		fgets(line, MAX, fp);
		fgets(plain, LEN, fp);
		len = strlen(plain);
		while(!isalpha(plain[len - 1])){
			plain[len - 1] = '\0';
			len--;
		}
		tok = strtok(line, " \n");
		
		keyCount = 0;
		while((tok != NULL)){
			result = sMatch(tok, plain);
			if(result != FAIL){
				key[keyCount++] = result;
			}
			tok = strtok(NULL, " \n");
		}
		qsort(key, keyCount, sizeof(short), compareShort);
		for(result = 0; result < keyCount; result++){
			printf("%c", (char) key[result] + 'a');
			/*printf("%hd ", key[result]);*/
		}
		printf("\n");
	}
	return 0;
}