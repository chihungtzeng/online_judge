#include <stdio.h>
#include <string.h>
#define MAX 64
#define DEAD 1
#define ALIVE 0


int main(){
	char discard[MAX];
	char life[MAX];
	short nCard, i, start, nDiscard, survivor, count;
	

	while(1){
		scanf("%hd",&nCard);
		if(0 == nCard){
			break;
		}
		if(1 == nCard){
			printf("Discarded cards:\n");
			printf("Remaining card: %d\n",1);
			continue;
		}
		
		memset(discard, 0, MAX);
		memset(life, ALIVE, MAX);
		discard[1] = 1;
		life[1] = DEAD;
		nDiscard = 1;
		start = 1;
	
		while(nDiscard < nCard){
			count = 0;
			while(count != 2){
				start = (start == nCard)? 1 : start + 1;
				if(life[start] == ALIVE){
					count++;
				}
			}
			nDiscard++;
			discard[nDiscard] = start;
			life[start] = DEAD; 
			survivor = start;
		}
		
		printf("Discarded cards: %d", 1);
		for(i=2; i<nDiscard; i++){
			printf(", %d", discard[i]);
		}
		printf("\n");
		printf("Remaining card: %d\n",survivor);
	}	
	
	return 0;
}