#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 102
#define DEBUG 0

struct Task{
	/*char outDegree; the number of projects it depends on*/
	char inDegree; /*the number of projects that depends on it*/
	char nDep;
	char dep[MAX];	
};

struct Answer{
	char round, index;
};

int compareAnswer(const void *a, const void *b){
	struct Answer *x, *y;
	x = (struct Answer *)a;
	y = (struct Answer *)b;
	if(x->round != y->round) return y->round - x->round;
	else return x->index - y->index;
}

void calcInDegree(char nTask, struct Task task[MAX]){
	char i,j, k;
		for(i=1; i<=nTask; i++){
		for(j=0; j<task[i].nDep; j++){
			task[task[i].dep[j]].inDegree += 1;
		}
	}
}

void topoSort(char nTask, struct Task task[MAX]){
	char i, j;
	char pool[MAX];
	char poolSize = nTask;
	char newPoolSize;
	struct Answer ans[MAX];
	char  nAns = 0;
	
	
	char curTask;
	char round = 0;
	
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
				ans[nAns].index = curTask;
				ans[nAns++].round = round;
				/*mark the position of the pool*/
				pool[i] = 0;
				#if DEBUG
				printf("found task %hhd at round %hhd\n", curTask, round);
				#endif
			}
		}
		for(i=0; i<newFound; i++){
			curTask = found[i];
			/*update inDegree for other tasks*/
				for(j=0; j<task[curTask].nDep; j++){
					task[task[curTask].dep[j]].inDegree -= 1;
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
	qsort(ans, nAns, sizeof(struct Answer), compareAnswer);
	printf("%hhd", ans[0].index);
	for(i=1; i<nTask; i++){
		printf(" %hhd", ans[i].index);
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
			task[taskId].nDep = nDep;
			for(j=0; j<nDep; j++){
				fscanf(fp, "%hhd", &(task[taskId].dep[j]));
			}
		}
		calcInDegree(nTask, task);
		
		#if DEBUG
		for(i=0; i<=nTask; i++){
			printf("%hhd: ", i);
			for(j=0; j<task[i].nDep; j++){
				printf("%hhd ", task[i].dep[j]);
			}
			
			printf("inDegree = %hhd\n", task[i].inDegree);
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

