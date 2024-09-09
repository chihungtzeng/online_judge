#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>
#define MAX 65536

int compareUS(const void *a, const void *b){
	unsigned short x, y;
	x = *(unsigned short *)a;
	y = *(unsigned short *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

unsigned short *newUS(unsigned short a){
	unsigned short *us;
	us = (unsigned short *) malloc(sizeof(unsigned short));
	*us = a;
	return us;
}

int addIfNotPresent(unsigned short x, void **root, int *nNew, unsigned short *newSet){
	void *match;
	unsigned short *us;
	us = newUS(x);
	match = *(unsigned short **) tsearch(us, root, compareUS);
	if(match == us){
		newSet[*nNew] = x;
		*nNew += 1;
		return EXIT_SUCCESS;
	} else{
		free(us);
		return EXIT_FAILURE;
	}
} 


int completeSet(int nEle, unsigned short *set){
	int ans = 0, i, j, nCheck, nNew, nGen;
	void *root = NULL;
	unsigned short *checkSet, *newSet, *genSet;
	unsigned short *us, *ANDresult, *ORresult;
	genSet = set;
	checkSet = (unsigned short *) malloc(sizeof(unsigned short)*MAX);
	newSet = (unsigned short *) malloc(sizeof(unsigned short)*MAX);
	for(i=0; i<nEle; ++i){
		us = newUS(set[i]);
		tsearch(us, &root, compareUS);
	}
	
	nGen = nEle;
	nCheck = 0;
	nNew = 0;
	do{
		/* generate new elements from genSet * genSet, and put them in newSet*/
		for(i=0; i<nGen; ++i){
			for(j=i+1; j<nGen; ++j){
				addIfNotPresent(genSet[i] & genSet[j], &root, &nNew, newSet);
				addIfNotPresent(genSet[i] | genSet[j], &root, &nNew, newSet);
			}
		}
		/*generate new elements from genSet * checkSet, and put them in newSet*/
		for(i=0; i<nGen; ++i){
			for(j=0; j<nCheck; ++j){
				addIfNotPresent(genSet[i] & checkSet[j], &root, &nNew, newSet);
				addIfNotPresent(genSet[i] | checkSet[j], &root, &nNew, newSet);
			}
		}
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
	tdestroy(root, free);
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
		set = (unsigned short *) malloc(sizeof(unsigned short)*MAX); 
		for(i=0; i<nEle; i++){
			scanf("%hu", &set[i]);
		}
		ans = completeSet(nEle, set);
		printf("Case #%hd: %d\n", k++, ans);
	}
	return 0;
}
