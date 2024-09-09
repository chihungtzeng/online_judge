#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 102
#define DEBUG 0

struct Task{
	/*char outDegree; the number of projects it depends on*/
	char outDegree; /*the number of projects that depends on it*/
	char nDepBy;
	char depBy[MAX];
	char hasVisit;	
};



void topoSort(char nTask, struct Task task[MAX]){
	char i, j, k;
	char pool[MAX];
	char poolSize = nTask;
	char newPoolSize;
	char output[MAX], nOutput = 0;
	char curTask;
	char curBest;

	for(i=1; i <= nTask; i++){
		curBest = MAX;
		for(curTask = 1; curTask <= nTask; curTask++){
			if((task[curTask].outDegree == 0) && (!task[curTask].hasVisit)){
				if(curBest > curTask){
					curBest = curTask;
				}
			}
		} 
		/*printf("curBest = %hhd\n", curBest);*/
		output[nOutput++] = curBest;
		task[curBest].hasVisit = 1;
		for(j=0; j<task[curBest].nDepBy; j++){
			k = task[curBest].depBy[j];
			task[k].outDegree -= 1;
		}
	}
	
	
	printf("%hhd", output[0]);
	for(i=1; i<nOutput; i++){
		printf(" %hhd", output[i]);
	}
	printf("\n");
}

int main(){
	struct Task task[MAX];
	int nTest;
	char nTask, nRule, taskId, nDep;
	char target;
	char i, j, first = 1;
	FILE *fp;
	
	
	fp = (DEBUG)? fopen("in.txt", "r"): stdin;
	fscanf(fp, "%d", &nTest);
	while(nTest--){
		memset(task, 0, sizeof(struct Task)*MAX);
		fscanf(fp, "%hhd %hhd", &nTask, &nRule);
		for(i=0; i<nRule; i++){
			fscanf(fp, "%hhd %hhd", &taskId, &nDep);
			task[taskId].outDegree = nDep;		
			for(j=0; j<nDep; j++){
				fscanf(fp, "%hhd", &target);
				task[target].depBy[task[target].nDepBy++] = taskId;
			}
		}
		
		
		#if DEBUG
		for(i=0; i<=nTask; i++){
			printf("%hhd: ", i);
			for(j=0; j<task[i].nDepBy; j++){
				printf("%hhd ", task[i].depBy[j]);
			}
			
			printf("inDegree = %hhd\n", task[i].outDegree);
		}
		#endif
		if(first){
			first = 0;
		} else{
			printf("\n");
		}
		if(nTask > 0){
			topoSort(nTask, task);
		} else {
			printf("\n");
		}
	}
	return 0;
}

