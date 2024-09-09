#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 15
#define LANG_NUM 6

struct Entry{
	char hello[LEN];
	char lang[LEN];
};

int compareEntry(const void *a, const void *b){
	struct Entry *x, *y;
	x = (struct Entry *)a;
	y = (struct Entry *)b;
	return strcmp(x->hello, y->hello);
}

void buildTable(struct Entry entry[LANG_NUM]){
	strcpy(entry[0].hello, "HELLO");
	strcpy(entry[0].lang, "ENGLISH");
	
	strcpy(entry[1].hello, "HOLA");
	strcpy(entry[1].lang, "SPANISH");
	
	strcpy(entry[2].hello, "HALLO");
	strcpy(entry[2].lang, "GERMAN");
	strcpy(entry[3].hello, "BONJOUR");
	strcpy(entry[3].lang, "FRENCH");
	strcpy(entry[4].hello, "CIAO");
	strcpy(entry[4].lang, "ITALIAN");
	strcpy(entry[5].hello, "ZDRAVSTVUJTE");
	strcpy(entry[5].lang, "RUSSIAN");
	qsort(entry, LANG_NUM, sizeof(struct Entry), compareEntry);
}

int main(){
	struct Entry entry[LANG_NUM], query, *ans;
	void *match;
	int k=1;
	buildTable(entry);
	while(1 == scanf("%s", query.hello)){
		if(query.hello[0] == '#') break;
		
		match = bsearch(&query, entry, LANG_NUM, sizeof(struct Entry), compareEntry);
		if(match){
			ans = (struct Entry *) match;
			printf("Case %d: %s\n", k++, ans->lang);
		} else {
			printf("Case %d: UNKNOWN\n", k++);
		}
	}
	
	return 0;
}
