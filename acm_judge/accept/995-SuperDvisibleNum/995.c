#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FAILURE -1
#define SUCCESS 1
#define YES 1
#define NO 0
#define MAXDIGIT 10
#define DEBUG 0

int base, nAllow;
char allow[MAXDIGIT];

int compareChar(const void *a, const void *b){
	return *(char *)a - *(char *)b;
}

int dividable(char *s, int n, int base){
	int i, r, len;
	if(NULL == s) return NO;
	len = strlen(s);
	r = 0;
	for(i=0; i < len; i++){
		r = (r*base + (s[i] - '0')) % n; 
	} 
	if (0 == r) return YES;
	else return NO;
}

int compareString(char *s, char *t){
	int slen, tlen;
	slen = strlen(s);
	tlen = strlen(t);
	if (slen > tlen){
		return 1;
	}
	else if (slen < tlen){
		return -1;
	}
	else{
		return strcmp(s,t);
	}
}



void append(char *s, char c){
	int len;
	len = strlen(s);
	s[len+1] ='\0';
	s[len] = c;
}

char *findAns(char *prefix, int depth){
	int i;
	char *apple, *grape;
	char *max, *candidate;
	int state = FAILURE;
	
	apple = (char *) malloc(51);
	max = (char *) malloc(51);
	
	strcpy(max, prefix);
	strcpy(apple,prefix);
	
	for(i=0; i < nAllow; i++){
		append(apple, allow[i]);
		if( dividable(apple, depth+1, base) == YES ){
			candidate = findAns(apple, depth + 1);
			if (compareString(candidate, max) > 0){
				strcpy(max, candidate);
				free(candidate);
			}
		}
		apple[strlen(apple) - 1] = '\0';
	}
	free(apple);
	return max;

}



int main(){
	char tmp[MAXDIGIT+1];
	int i;
	char *try, *candidate;
	FILE *fp;
	char *ans;
	
	if(DEBUG){
		fp = fopen("in.txt","r");
	}
	else{
		fp = stdin;
	}
	try = (char *) malloc(sizeof(char)*51);
	ans = (char *) malloc(sizeof(char)*51);
	
	
	while(2 == fscanf(fp, "%d %s",&base, tmp)){
		ans[0] = '\0';
		qsort(tmp, strlen(tmp), sizeof(char), compareChar);

		allow[0] = tmp[0];
		nAllow = 1;
		for(i=1;i<strlen(tmp);i++){
			if(tmp[i] != tmp[i-1]){
				allow[nAllow++] = tmp[i];
			}
		}
		if(DEBUG){
			printf("base: %d, allow digits: %s\n",base, tmp);
			printf("allowed digits:");
			for(i=0;i<nAllow;i++){
				printf("%c ", allow[i]);
			}
			printf("\n");
		}
		
		for(i = 0; i < nAllow; i++){
			if(allow[i] != '0'){
				try[0] = allow[i];
				try[1] = '\0';
				candidate = findAns(try, 1);
				if(compareString(candidate, ans)>0){
					strcpy(ans, candidate);
					free(candidate);
				}
			}
		}

		printf("%s\n",ans);
	}
	free(ans);
	free(try);

	return 0;
}

