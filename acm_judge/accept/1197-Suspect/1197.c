#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 501
#define FALSE 0
#define TRUE 1

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int hasSuspect(short target, short groupSize, short *group){
	void *match;
	match = bsearch(&target, group, groupSize, sizeof(group[0]), compareShort);
	if(match) return TRUE;
	else return FALSE;
}

int solve(short nPeople, short nGroup, short *groupSize, short **groupMember){
	char *bSuspect;
	short i, j;
	short nSuspect = 0;
	short head, tail, *queue;
	short curSuspect, nextSuspect;
	
	bSuspect = (char *) malloc(nPeople);
	memset(bSuspect, FALSE, nPeople);
	bSuspect[0] = TRUE;
	
	queue = (short *) malloc(sizeof(short) * nPeople);
	head = 0;
	tail = 1;
	queue[0] = 0;	
	
	while(head < tail){
		curSuspect = queue[head++];
		for(i=0; i<nGroup; i++){
			if(hasSuspect(curSuspect, groupSize[i], groupMember[i])){
				for(j=0; j<groupSize[i]; j++){
					nextSuspect = groupMember[i][j];
					if(bSuspect[nextSuspect] == FALSE){
						bSuspect[nextSuspect] = TRUE;
						queue[tail++] = nextSuspect;
					}
				}
			}
		}
	}	
	
	for(i=0; i<nPeople; i++){
		if(bSuspect[i]) nSuspect++;
	}
	
	free(bSuspect);
	free(queue);
	return nSuspect;
}

int main(){
	short nPeople, nGroup;
	short *group[MAX];
	short i, j, groupSize[MAX];	
	
	FILE *fp = stdin;
	
	while(2 == fscanf(fp, "%hd %hd", &nPeople, &nGroup)){
		if((0 == nPeople) && (0 == nGroup)) {
			break;
		}
		
		
		for(i=0; i<nGroup; i++){
			fscanf(fp, "%hd", &groupSize[i]);
			group[i] = (short *) malloc(sizeof(short)*groupSize[i]);
			for(j=0; j<groupSize[i]; j++){
				fscanf(fp, "%hd", &group[i][j]);
			}
			qsort(group[i], groupSize[i], sizeof(short), compareShort);
		}
		
		printf("%d\n", solve(nPeople, nGroup, groupSize, group));
		
		
		for(i=0; i<nGroup; i++){
			free(group[i]);
		}
	}
	
	return 0;
}