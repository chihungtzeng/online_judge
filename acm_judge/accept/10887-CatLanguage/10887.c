#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MAX 12
#define MAXCAT 24
#define MAXN 1500
#define DEBUG 0

int compareString(const void *p1, const void *p2){
	char *s, *t;
	s = (char *)p1;
	t = (char *)p2;
	return strcmp(s, t);
}

int main(){
	short nTest, N, M, i, j, k=1;
	short leni, lenj;
	void *root;
	char line[MAX];
	char *newString;
	FILE *fp;
	char lang1[MAXN][MAX], lang2[MAXN][MAX];
	short langlen1[MAXN], langlen2[MAXN];
	int count;
	void *match;
	
	fp = (DEBUG)? fopen("shit.txt","r") : stdin;	
	
	fgets(line, MAX, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		fgets(line, MAX, fp);
		N = atoi(strtok(line, " \n"));
		M = atoi(strtok(NULL, " \n"));
		for(i=0; i<N; i++){
			fgets(lang1[i], MAX, fp);
			langlen1[i] = strlen(lang1[i]);
			while((langlen1[i] > 0) && !isalpha(lang1[i][langlen1[i] - 1])){
				lang1[i][langlen1[i] - 1] = '\0';
				langlen1[i] -= 1;
			} 
			if(DEBUG){
				printf("read lang1[%hd]=%s, len=%hd", i, lang2[i], langlen1[i]);
			}
		}
		for(i=0; i<M; i++){
			fgets(lang2[i], MAX, fp);
			langlen2[i] = strlen(lang2[i]);
			while((langlen2[i] > 0) && !isalpha(lang2[i][langlen2[i] - 1])){
				lang2[i][langlen2[i] - 1] = '\0';
				langlen2[i] -= 1;
			} 
			if(DEBUG){
				printf("read lang2[%hd]=%s, len=%hd", i, lang2[i], langlen2[i]);
			}
		}
		count = 0;
		root = NULL;
		for(i=0; i<N; i++){
			for(j=0; j<M; j++){
				if((langlen1[i] > 0) && (langlen2[j] > 0)){
					newString = (char *) malloc(sizeof(char)*20);
					strcpy(newString, lang1[i]);
					strcat(newString, lang2[j]);
				}
				else if ((langlen1[i] == 0) && (langlen2[j] > 0)){
					newString = strndup(lang2[j], langlen2[j]);
				}
				else if ((langlen1[i] > 0) && (langlen2[j] == 0)){
					newString = strndup(lang1[i], langlen1[i]);
				}
				else {
					newString = (char *) malloc(sizeof(char));
					newString[0] = '\0';
				}
				if(DEBUG){
					printf("newString =*%s*\n", newString);
				}
				
				match = tsearch(newString, &root, compareString);
				
				if(match == NULL){
					printf("insufficient memory\n");
					exit(0);
				}
				else if( (*(char **) match) == newString){
					count++;
				} 
				else{
					free(newString);
				}
				
			}
		}
		printf("Case %hd: %d\n",k++, count);
		tdestroy(root, free);
	}
	return 0;
}