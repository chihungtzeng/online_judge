#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define LEN 32

int compareChar(const void *a, const void *b){
	return *(char *)a - *(char *)b;
}

int compareString(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int *newInt(int n){
	int *ptr;
	ptr = (int *) malloc(sizeof(int));
	*ptr = n;
	return ptr;
}

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

void inverse(char sz[], char len){
	char i = 0, j = len - 1;
	while(i < j){
		sz[i] = sz[i] ^ sz[j];
		sz[j] = sz[i] ^ sz[j];
		sz[i] = sz[i] ^ sz[j];
		i++;
		j--;
	}
}


void solve(int n){
	void *root, *match;
	int iResult, iInc, iDec;
		
	int *iNew;
	char *incSz, *decSz, *substractResult, *tmp;
	short chainLen = 0;
	char curLen;
	root = NULL;
	incSz = (char *) malloc(LEN);
	decSz = (char *) malloc(LEN);
	
	curLen = sprintf(incSz, "%d", n);
	printf("Original number was %s\n", incSz);
	
	iNew = newInt(n);
	tsearch(iNew, &root, compareInt);
	
	do{				
		qsort(incSz, curLen, sizeof(char), compareChar);
		strcpy(decSz, incSz);
		inverse(decSz, curLen);
		iInc = atoi(incSz);
		iDec = atoi(decSz);
		iResult = iDec - iInc;

		printf("%d - %d = %d\n", iDec, iInc, iResult);
		curLen = sprintf(incSz, "%d", iResult );
		iNew = newInt(iResult);
		match = tsearch(iNew, &root, compareInt);
		
		if(*(int **)match != iNew){
			break;
		} else{
			chainLen++;
		}
	} while(1);
	printf("Chain length %hd\n\n", chainLen + 1);
	
	tdestroy(root, free);
	free(incSz);
	free(decSz);
}

int main(){
	
	short lineLen;
	int num;
	while(1 == scanf("%d", &num)){
		if(0 == num){
			break;
		} else{
			solve(num);
		}
	}
	return 0;
}
