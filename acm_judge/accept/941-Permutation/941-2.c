#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 21
#define DEBUG 0

long int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};

int compareChar(const void *a, const void *b){
	return *(char *)a - *(char *)b; 
}



char string_deleteCharAt(char *s, int pos, int len){
	char c = '\0';
	
	int i;
	if (NULL == s) return '\0';
	if ((pos < 0) || (pos >= len)) return '\0';
	c = s[pos];
	for(i = pos; i < len ; i++){
		s[i] = s[i+1];
	}
	
	return c;
}

int main(){
	int nTest;
	char *postfix, *prefix; 
	long int k;
	size_t len;
	long int nSubstring;
	long int firstCharPos;
	char firstChar;
	long int prelen, i;
	
	
	postfix = (char *)malloc(sizeof(char)*MAXCHAR);
	prefix = (char *)malloc(sizeof(char)*MAXCHAR);
	postfix[0] = '\0';
	prefix[0] = '\0';
	
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%s %ld",postfix, &k);
		prelen = 0;
		
		len = strlen(postfix);		
		qsort(postfix, len ,sizeof(char),compareChar);
		if(DEBUG) {printf("input string: %s, k=%ld\n",postfix, k);}
		/*findAns(postfix, prefix, k);*/	
		if(k >= fac[len]){
			if(DEBUG) {printf("No such permutation exists\n");}
			exit(0);
		}
		
		while(len >= 1){
			len--;
			nSubstring = fac[len];
			firstCharPos = k / nSubstring;
			k = k % nSubstring;
			prefix[prelen++] = postfix[firstCharPos];
			prefix[prelen] ='\0';
			postfix[firstCharPos] = '\0';
			/*memcpy(postfix+firstCharPos, postfix+firstCharPos+1, len - firstCharPos);*/
			
			for(i = firstCharPos; i < len ; i++){
				postfix[i] = postfix[i+1];
			}
			
		}
		/**/
		
		puts(prefix);
		postfix[0] = '\0';
		prefix[0] = '\0';
	}
	
	free(prefix);
	free(postfix);
	
	return 0;
}