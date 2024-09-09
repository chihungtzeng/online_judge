#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 65536

char inSet[MAX];



void addIfNotPresent(unsigned short x, int *nNew, unsigned short *newSet){
	if(inSet[x] == 0){
		newSet[*nNew] = x;
		inSet[x] = 1;	
		*nNew += 1;
	} 
} 


int completeSet(int nEle, unsigned short *set){
	int ans = 0, i, j, nCheck, nNew, nGen;
	
	unsigned short *checkSet, *newSet, *genSet;
	unsigned short *us, *ANDresult, *ORresult;
	genSet = set;
	checkSet = (unsigned short *) malloc(sizeof(unsigned short)*MAX);
	newSet = (unsigned short *) malloc(sizeof(unsigned short)*MAX);
	
	
	nGen = nEle;
	nCheck = 0;
	nNew = 0;
	do{
		/* generate new elements from genSet * genSet, and put them in newSet*/
		for(i=0; i<nGen; ++i){
			for(j=i+1; j<nGen; ++j){
				addIfNotPresent(genSet[i] & genSet[j], &nNew, newSet);
				addIfNotPresent(genSet[i] | genSet[j], &nNew, newSet);
			}
		}
		/*generate new elements from genSet * checkSet, and put them in newSet*/
		/*
		for(i=0; i<nGen; ++i){
			for(j=0; j<nCheck; ++j){
				addIfNotPresent(genSet[i] & checkSet[j], &nNew, newSet);
				addIfNotPresent(genSet[i] | checkSet[j], &nNew, newSet);
			}
		}
		*/
		/*append checkSet with genSet*/
		for(i=0; i<nGen; i++){
			checkSet[nCheck++] = genSet[i];
		}
		memcpy(genSet, newSet, sizeof(unsigned short)*nNew);
		ans += nNew;
		nGen = nNew;
		nNew = 0;
	} while(nGen > 0);
	/*
		
	*/
	free(checkSet);
	free(newSet);
	free(genSet);
	
	return ans;
}

int main(){
	short nTest, k = 1;
	int nEle, i, ans;
	unsigned short *set; 
	scanf("%hd", &nTest);
	
	while(nTest > 0){
		--nTest;
		scanf("%d", &nEle);
		memset(inSet, 0, MAX);
		set = (unsigned short *) malloc(sizeof(unsigned short)*MAX); 
		for(i=0; i<nEle; i++){
			scanf("%hu", &set[i]);
			inSet[set[i]] = 1;
		}
		ans = completeSet(nEle, set);
		printf("Case #%hd: %d\n", k++, ans);
	}
	return 0;
}
