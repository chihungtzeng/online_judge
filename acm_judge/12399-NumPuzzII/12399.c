#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#include <assert.h>

struct Cell {
	char row, column;
	char nNeighbor;
	char neighbor[9];
};

struct Config {
	int solutionLen;
	char content[10];
	char *pSolution;
	
};

struct QueueElement {
	void *pObj;
	struct QueueElement *pNext;
};

struct QueueElement *newQueueElement(void *pObj){
	struct QueueElement *pQueueElement;
	pQueueElement = (struct QueueElement *) malloc(sizeof(struct QueueElement));
	pQueueElement->pObj = pObj;
	pQueueElement->pNext = NULL;
	return pQueueElement;
}

struct QueueElement *appendElement(struct QueueElement *pFront, struct QueueElement *pRear){
	pFront->pNext = pRear;
	return pRear;
}


struct Config *newConfig(){
	struct Config *pConfig;
	
	pConfig = (struct Config *) malloc(sizeof(struct Config));
	/*memset(pConfig->content, 0, sizeof(pConfig->content));*/
	pConfig->content[0] = '\0';
	pConfig->solutionLen = 0;
	pConfig->pSolution = NULL;
	return pConfig;
}

void printConfig(struct Config *pConfig){
	printf("content=\"%s\" solution=\"%s\"\n", pConfig->content, pConfig->pSolution);
}

void checkConfig(struct Config *pConfig){
	int i;
	char c;
	for(i=0; i<9; i++){
		c = pConfig->content[i]; 
		if((c < '0') || (c > '9')){
			printConfig(pConfig);
			assert(0);
		} 
	}
}

struct Config *nextConfig(struct Config *pConfig, char move, struct Cell cell[9]){
	int i, nbr;
	struct Config *pResult;
	pResult = newConfig();
	strcpy(pResult->content, pConfig->content);
	for(i=0; i<cell[move].nNeighbor; i++){
		nbr = cell[move].neighbor[i];
		pResult->content[nbr] += 1;
		if(pResult->content[nbr] > '9'){
			pResult->content[nbr] = '0';
		}
	}
	return pResult;
}

int compareConfig(const void *a, const void *b){
	struct Config *x, *y;
	x = (struct Config *)a;
	y = (struct Config *)b;
	return strcmp(x->content, y->content);
}

void freeConfig(void *pObj){
	struct Config *pConfig;
	pConfig = (struct Config *) pObj;
	if(pConfig->pSolution != NULL){
		free(pConfig->pSolution);
		pConfig->pSolution = NULL;
	}
	free(pObj);
}

int validPos(int pos){
	if((pos >=0) && (pos < 3)) return 1;
	else return 0;
}

void initCell(struct Cell cell[9]){
	int i, j, k, newRow, newCol, newNbr;
	for(i=0; i<9; i++){
		cell[i].row = i / 3;
		cell[i].column = i % 3;
		cell[i].neighbor[0] = i;
		cell[i].nNeighbor = 1;
	}

	for(i=0; i<9; i++){
		for(j=-1; j<=1; j++){
			for(k=-1; k<=1; k++){
				if(abs(j) + abs(k) != 1){
					continue;
				}
				newRow = cell[i].row + j;
				newCol = cell[i].column + k;
				if(validPos(newRow) && validPos(newCol)){
					newNbr = (newRow << 1) + newRow + newCol;
					cell[i].neighbor[cell[i].nNeighbor] = newNbr;
					cell[i].nNeighbor += 1;
				}
			}
		}
	}	
#if 0
	for(i=0; i<9; i++){
		printf("cell %d (%d %d): ",i, cell[i].row, cell[i].column);
		for(j=0; j<cell[i].nNeighbor; j++){
			printf("%d ", cell[i].neighbor[j]);
		}
		printf("\n");
	}
#endif
}


void calcBestSolution(struct Config *pCurConfig, struct Config *pNextConfig, int move){
	pNextConfig->solutionLen = pCurConfig->solutionLen + 1;
	pNextConfig->pSolution = (char *) malloc(pNextConfig->solutionLen);
	strcpy(pNextConfig->pSolution, pCurConfig->pSolution);
	
	pNextConfig->pSolution[pCurConfig->solutionLen] = move + 'a';
	pNextConfig->pSolution[pCurConfig->solutionLen + 1] = '\0';
	
}

void twalkAction(const void *pRoot, const VISIT way, const int depth){
	if((way == postorder) || (way == leaf)){
		struct Config *pConfig;
		pConfig = *(struct Config **) pRoot;
		printConfig(pConfig);
	}
}

void findSolution(void **ppRoot, struct Cell cell[9]){
	struct Config *pNextConfig, *pCurConfig;
	struct Config *pInitConfig;
	void *match;
	int move;
	struct QueueElement *pTail, *pCur, *pTmp;
	int count = 0;
	
	pInitConfig = newConfig();
	memset(pInitConfig->content, '0', 9);
	pInitConfig->content[10] = '\0';
	pInitConfig->pSolution = (char *) malloc(sizeof(char));
	pInitConfig->pSolution[0] = '\0';
	printConfig(pInitConfig);	

	tsearch(pInitConfig, ppRoot, compareConfig);
	pCur = newQueueElement((void *)pInitConfig);
	pTail = pCur;
	
	while(pCur != NULL){
		pCurConfig = (struct Config *) pCur->pObj;
		for(move=0; move<9; move++){
			pNextConfig = nextConfig(pCurConfig, move, cell);
			checkConfig(pNextConfig);
			match = tfind(pNextConfig, ppRoot, compareConfig);
			if(!match){
				calcBestSolution(pCurConfig, pNextConfig, move);
				tsearch(pNextConfig, ppRoot, compareConfig);
				pTmp = newQueueElement(pNextConfig);
				pTail = appendElement(pTail, pTmp);
				count++;
				if(count % 100000 == 0){
					printf("found %d entries, solutionLen=%d\n", count, pNextConfig->solutionLen);
				}
			}
			else {
			#if 0
				printf("visited: %s\n", pNextConfig->content);
				#endif
				freeConfig(pNextConfig);
			}
		}
		pTmp = pCur;
		pCur = pCur->pNext;
		free(pTmp);
	}
	printf("DONE !\n");
	twalk(*ppRoot, twalkAction);
}

int main(){
	struct Cell cell[9];
	
	void *root = NULL;
	
	initCell(cell);
	
	findSolution(&root, cell);
	
	return 0;	
}