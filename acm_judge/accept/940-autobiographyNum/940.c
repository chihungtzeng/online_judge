#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 102
#define DEBUG 1
#define VERBOSE 0
#define SUCCESS 1
#define FAIL 0;

struct aNum{
	short quota;
	short length;
	short pos;
	short nDigit;
	short digit[MAX];
	short avail[MAX];
};

struct aNum *aNumList[MAX*MAX];
short nANum;

void printANum(struct aNum *x){
	short i;
	if(x == NULL){
		printf("cannot print null autobiographical num\n");
		return ;
	}
	printf("{");
	for(i=0; i < x->length - 1; i++){
		printf("%hd,",x->digit[i]);
	}
	printf("%hd},",x->digit[x->length - 1]);
	
	if(VERBOSE){
		printf(" length: %hd, pos:%hd quota:%hd", x->length, x->pos, x->quota);
		printf(" avail:(", x->length, x->pos, x->quota);
		for(i=0; i< x->length; i++){
			printf("%hd ", x->avail[i]);
		}
		printf(")");
	}
	printf("\n");
}

int discover(struct aNum *curNum){
	struct aNum *nextANum;
	short state = FAIL;
	
	if(curNum == NULL){
		printf("null autobio num\n");
		return FAIL;
	}
	if(curNum->quota > curNum->length){
		printf("quota exceeds!\n");
		return FAIL;
	}
	
	if(curNum->pos == curNum->length - 1){
		if(VERBOSE){
			printf("reach recursion buttom\n");
			printANum(curNum);
		}
		short sum, i, useup;
		sum = 0;
		useup = 1;
		for(i=0; i<curNum->length; i++){
			sum += curNum->digit[i];
			if(curNum->avail[i] > 0){
				useup = 0;
			}
		}
		if((sum == curNum->length) && (useup == 1)){
			/*discover an autobiographical number!*/
			aNumList[nANum] = (struct aNum *) malloc(sizeof(struct aNum));
			memcpy(aNumList[nANum], curNum, sizeof(struct aNum));
			nANum++;
			return SUCCESS;
		}
		return FAIL;
	}
	nextANum = (struct aNum *) malloc(sizeof(struct aNum));
	

	int i,j, irange;
	irange = ((curNum->length - curNum->quota) / curNum->pos);
	for(i=0; 
		(curNum->quota + i * curNum->pos <= curNum->length) && 
		(curNum->nDigit + i <= curNum->length) ; 
		i++){
	/*fill the digit[pos] with number i*/

		if((i < curNum->pos) && (curNum->avail[i] > 0)){
			memcpy(nextANum, curNum, sizeof(struct aNum));
			nextANum->avail[curNum->pos] = i;
			nextANum->digit[curNum->pos] = i;
			for(j=0; j <= curNum->pos; j++){
				if(nextANum->digit[j] == curNum->pos){
					nextANum->avail[curNum->pos] -= 1;
				}
			}
			if(nextANum->avail[curNum->pos] >= 0){
				nextANum->avail[i] -= 1;				
				nextANum->quota += i * curNum->pos;
				nextANum->pos += 1;
				nextANum->nDigit += i;
				state = discover(nextANum);
			}
		}

		if( i >= curNum->pos){
			memcpy(nextANum, curNum, sizeof(struct aNum));
			nextANum->avail[curNum->pos] = i;
			nextANum->digit[curNum->pos] = i;
			for(j=0; j <= curNum->pos; j++){
				if(nextANum->digit[j] == curNum->pos){
					nextANum->avail[curNum->pos] -= 1;
				}
			}
			if(nextANum->avail[curNum->pos] >= 0){
				nextANum->nDigit += i;
				nextANum->quota += i * curNum->pos;
				nextANum->pos += 1;
				state = discover(nextANum);
			}
		}
	}

	free(nextANum);
	return state;	
}

void discoverAutoNumForLength(int alen){
	struct aNum *baseANum;
	short i,j;
	baseANum = (struct aNum *) malloc(sizeof(struct aNum));
	

	memset(baseANum->digit, 0, sizeof(char)*MAX);
	baseANum->length = alen;
	for(j=1; j <= alen - 2 ; j++){
		baseANum->digit[0] = j;
		baseANum->nDigit = j;
		baseANum->avail[0] = j - 1; /*The last digit must be 0, so j - 1*/
		baseANum->quota = 0;
		baseANum->pos = 1;
		discover(baseANum);
	}
	free(baseANum);
}

int main(){
	int nTest;
	int curlen;
	char alphabet[MAX];
	short first, len, i, j;

	
	first = 1;
	nANum = 0;
	curlen = 3;	
	if(DEBUG){
		for(i=4; i<=40; i++){
			fprintf(stderr, "processing length: %d\n",i);
			discoverAutoNumForLength(i);
		}	
		printf("find %d autobiographical num\n",nANum);
		for(i=0; i<nANum; i++){
			printANum(aNumList[i]);
		}	
	}

/*
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		if(!first){
			printf("\n");
		}
		else{
			first = 0;
		}
		
		scanf("%s", alphabet);
		
		len = strlen(alphabet);
		if(len < 4){
			printf("\n");
			continue;
		}
		if(len > curlen){
			for(i=curlen + 1; i<= len; i++){
				discoverAutoNumForLength(i);
			}
			curlen = len;
		}
		

		for(i=0; i< nANum; i++){
			for(j=0; j<aNumList[i]->length; j++){
				printf("%c",alphabet[aNumList[i]->digit[j]]);
			}
			printf("\n");
		}
	}	
	*/
	for(i=0; i<nANum; i++){
		free(aNumList[i]);
	}
	return 0;
}