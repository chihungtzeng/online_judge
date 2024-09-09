#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 8

struct DictEntry{
	char org[LEN];
	char sorted[LEN];
};

int compareChar(const void *a, const void *b){
	return *(char *)a - *(char *)b;
}

int compareDictEntry(const void *a, const void *b){
	struct DictEntry *x, *y;
	int result;
	x = (struct DictEntry *) a;
	y = (struct DictEntry *) b;
	result = strcmp(x->sorted, y->sorted);
	if(result) return result;
	else return strcmp(x->org, y->org);
}

int myBsearch(int nEntry, struct DictEntry *dictEntry, char query[]){
	int left = 0 , right = nEntry - 1, middle;
	int found = 0, result;
	while(left <= right){
		middle = (left + right) >> 1;
		result = strcmp(query, dictEntry[middle].sorted); 
		if(result == 0){
			found = 1;
			break;
		} else if (result < 0){
			right = middle - 1;
		} else {
			left = middle + 1;			
		}
	}
	if(!found){
		middle = -1;
	} else{
		while((middle >= 0) && (strcmp(query, dictEntry[middle].sorted) == 0)){
			middle--;
		}
		middle++;
	}
	return middle;
}

void doQuery(int nEntry, struct DictEntry *dictEntry, char query[]){
	int idx;
	qsort(query, strlen(query), sizeof(char), compareChar);
	#if 0
	printf("query string:%s\n", query);
	#endif
	idx = myBsearch(nEntry, dictEntry, query);
	if(idx < 0){
		puts("NOT A VALID WORD");
	} else{
		while( (idx < nEntry) && (strcmp(query, dictEntry[idx].sorted) == 0)){
			puts(dictEntry[idx].org);
			idx++;
		}
	}
	puts("******");
}


int main(){
	struct DictEntry *dictEntry;
	int nEntry = 0;
	int maxEntry = 1024;
	int i;
	char query[LEN];
	FILE *fp = stdin;
	dictEntry = (struct DictEntry *) malloc(sizeof(struct DictEntry)*maxEntry);
	while(1 == fscanf(fp, "%s", dictEntry[nEntry].org)){
		if(strcmp(dictEntry[nEntry].org, "XXXXXX") != 0){
			/*more dict entry*/
			strcpy(dictEntry[nEntry].sorted, dictEntry[nEntry].org);
			qsort(dictEntry[nEntry].sorted, 
				strlen(dictEntry[nEntry].sorted), 
				sizeof(char), compareChar);
			nEntry++;
			if(nEntry == maxEntry){
				maxEntry <<= 1;
				dictEntry = realloc((void *)dictEntry, 
					sizeof(struct DictEntry)*maxEntry);
			}
		} else {
			break;
		}
	}
	qsort(dictEntry, nEntry, sizeof(struct DictEntry), compareDictEntry);
	
	#if 0
	for(i=0; i<nEntry; i++){
		printf("%s %s\n", dictEntry[i].org, dictEntry[i].sorted);
	}
	#endif
	while(1 == fscanf(fp, "%s", query)){
		if(strcmp(query, "XXXXXX") != 0){
			doQuery(nEntry, dictEntry, query);
		} else {
			break;
		}
	}
	
	free(dictEntry);
	return 0;
}
