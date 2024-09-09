/*Time Limit Exceed*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 20

struct landscape{
	unsigned short nPlus, nMinus;
	unsigned short height[2*MAXN];
	unsigned int curPos;
};

unsigned int count;
unsigned short n, r, k;
unsigned short stop;

unsigned short checkValid(struct landscape *ls){
	unsigned short cnt = 0, i;
	if((NULL == ls) || (ls->curPos < stop)){
		printf("lscape is invalid when checking");
		return 0;
	}
	for(i = stop; i >= 1; i--){
		if((ls->height[i] == k) && (ls->height[i] > ls->height[i-1]) && (ls->height[i] > ls->height[i+1])){
			cnt++;
		}
	}
	if(cnt == r) return 1;
	else return 0;
}

void findAns(struct landscape *lscape){
	unsigned int i;
	struct landscape *newls;
	
	if(lscape == NULL){
		printf("Bug found\n");
		return ;
	}
	if(lscape->curPos == stop){
		count += checkValid(lscape);
		return ;
	}
	if(0 == lscape->nPlus){
		for(i = lscape->curPos; i < stop;i++){
			lscape->height[i] = lscape->height[i-1] - 1; 
		}
		lscape->curPos = stop;
		count += checkValid(lscape);
		return ;
	}
	if (0 == lscape->nMinus){
		for(i = lscape->curPos; i < stop; i++){
			lscape->height[i] = lscape->height[i-1] + 1; 
		}
		lscape->curPos = stop;
		count += checkValid(lscape);
		return ;
	}
	
	/*go uphill*/
	newls = (struct landscape *) malloc(sizeof(struct landscape));
	memcpy(newls, lscape, sizeof(struct landscape));
	newls->nPlus -= 1;
	newls->height[newls->curPos] = newls->height[newls->curPos - 1] + 1;
	newls->curPos += 1;
	findAns(newls);
	free(newls);
	/*downhill*/
	if(lscape->height[lscape->curPos - 1] > 0){
		newls = (struct landscape *) malloc(sizeof(struct landscape));
		memcpy(newls, lscape, sizeof(struct landscape));
		newls->nMinus -= 1;
		newls->height[newls->curPos] = newls->height[newls->curPos - 1] - 1;
		newls->curPos += 1;
		findAns(newls);
		free(newls);
	}
}

int main(){
	struct landscape *lscape;
	while(3 == scanf("%hu %hu %hu",&n, &r, &k)){
		if(n == 1){
			if((r == 1) && (1 == k)){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
			continue;
		}
		count = 0;
		stop = 2*n - 1;
		lscape = (struct landscape *) malloc(sizeof(struct landscape));
		lscape->height[0] = 0;
		lscape->height[1] = 1;
		lscape->height[2*n - 1] = 1;
		lscape->height[2*n] = 0;
		lscape->curPos = 2;
		lscape->nPlus = n - 1;
		lscape->nMinus = n - 1;
		findAns(lscape);
		printf("%u\n",count); 
		free(lscape);
	}
	return 0;
}
