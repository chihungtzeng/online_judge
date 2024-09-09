/*WA*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 102
#define DEBUG 0

struct Task{
	/*char outDegree; the number of projects it depends on*/
	char inDegree; /*the number of projects that depends on it*/
	char nDepBy;
	char depBy[MAX];	
};


void calcInDegree(char nTask, struct Task task[MAX]){
	char i,j, k;
		for(i=1; i<=nTask; i++){
		for(j=0; j<task[i].nDepBy; j++){
			task[task[i].depBy[j]].inDegree += 1;
		}
	}
}

void topoSort(char nTask, struct Task task[MAX]){
	char i, j;
	char pool[MAX];
	char poolSize = nTask;
	char newPoolSize;
	
	char done = 0;
	char curTask;
	char round = 0;
	char output[MAX], nOutput = 0;
	char found[MAX], newFound = 0;

	for(i=1; i<=nTask; i++){
		pool[i] = i;
	}
	
	while(poolSize > 0){
		/*extract sink*/
		newFound = 0;
		for(i=1; i<=poolSize; i++){
			curTask = pool[i];
			if(task[curTask].inDegree == 0){
				/*find a sink*/
				
				found[newFound++] = curTask;
				
				/*mark the position of the pool*/
				pool[i] = 0;
				#if DEBUG
				printf("found task %hhd at round %hhd\n", curTask, round);
				#endif
			}
		}
		for(i=0; i<newFound; i++){
			curTask = found[i];
			output[nOutput++] = curTask;
			/*update inDegree for other tasks*/
				for(j=0; j<task[curTask].nDepBy; j++){
					task[task[curTask].depBy[j]].inDegree -= 1;
				}
		}
		for(i=1, newPoolSize = 0; i<=poolSize; i++){
			if(pool[i]){
				pool[++newPoolSize] = pool[i];
			}
		}
		poolSize = newPoolSize;
		round++;
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
			
			for(j=0; j<nDep; j++){
				fscanf(fp, "%hhd", &target);
				task[target].depBy[task[target].nDepBy] = taskId;
				task[target].nDepBy += 1;
			}
		}
		calcInDegree(nTask, task);
		
		#if DEBUG
		for(i=0; i<=nTask; i++){
			printf("%hhd: ", i);
			for(j=0; j<task[i].nDepBy; j++){
				printf("%hhd ", task[i].depBy[j]);
			}
			
			printf("inDegree = %hhd\n", task[i].inDegree);
		}
		#endif
		if(first){
			first = 0;
		} else{
			printf("\n");
		}
		topoSort(nTask, task);
	}
	return 0;
}

