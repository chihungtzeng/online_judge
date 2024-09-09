#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define LEN 2048

struct Person{
	char name[16];
	short give, receive;
};

short personSearch(char name[], short nPerson, struct Person person[]){
	short i;
	for(i=0; i<nPerson; i++){
		if(!strcmp(name, person[i].name)) return i;
	}
	printf("No match!\n");
	assert(i < nPerson);
	return 0;
}

int main(){
	short nPerson, i, j, giverIndex, takerIndex, nTaker;
	char giverName[16], takerName[16];
	short giveAmount, receiveAmount, totalGive;
	struct Person person[16];
	char first=1;
	FILE *fp = stdin;

	while(1 == scanf("%hd", &nPerson)){
		memset(person, 0, sizeof(struct Person)*nPerson);
		for(i=0; i<nPerson; i++){
			scanf("%s", person[i].name);
		}
		for(i=0; i<nPerson; i++){
			scanf("%s %hd %hd", giverName, &totalGive, &nTaker);
			giverIndex = personSearch(giverName, nPerson, person);
			if(nTaker == 0) continue;
			receiveAmount = totalGive / nTaker;
			person[giverIndex].give = receiveAmount * nTaker;
			for(j=0; j<nTaker; j++){
				scanf("%s", takerName);
				takerIndex = personSearch(takerName, nPerson, person);
				person[takerIndex].receive += receiveAmount;
			}
		}
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		for(i=0; i<nPerson; i++){
			printf("%s %d\n",person[i].name, -person[i].give + person[i].receive);
		}
	}
	return 0;
}