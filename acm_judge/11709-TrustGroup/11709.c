#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include <search.h>

#define LEN 32

int main(){
	char line[LEN];
	FILE *fp = stdin;
	int nPeople, nRelation;
	int i, j;
	int id[2];
	ENTRY *entry, query, *match;
	
	query.key = (char *) malloc(LEN);
	entry = (ENTRY *) malloc(sizeof(ENTRY)*1001);	
	
	while(NULL != fgets(line, LEN, fp)){
		sscanf(line, "%d %d", &nPeople, &nRelation);
		if(nPeople == 0) break;
		

		hcreate(nPeople << 2);		
		for(i=0; i<nPeople; i++){
			entry[i].key = (char *) malloc(LEN);
			fgets(entry[i].key, LEN, fp);
			entry[i].data = (void *) i;
			hsearch(entry[i], ENTER);  
		}
		
		for(i = 0; i <nRelation; i++){
			for(j=0; j<2; j++){
				fgets(query.key, LEN, fp);
				match = hsearch(query, FIND);
				if(!match){
					printf("[ERR] no match for %s\n", query.key);
					return 1;
				}
				id[j] = (size_t) match->data;
				#if 0
				printf("%s has id %d\n", query.key, id[j]);
				#endif
			}
		}
		for(i=0; i<nPeople; i++){
			free(entry[i].key);
		}
		hdestroy();
	}	
	
	free(entry);
	free(query.key);
	return 0;
	
}