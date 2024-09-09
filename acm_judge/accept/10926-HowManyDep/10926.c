#include <stdio.h>
#define MAX 102

struct Task{
	char degree;
	char neighbor[MAX];
	char nDep;
};

char BFS(char start, char nTask, struct Task task[]){
	char queue[MAX], head = 0, tail = 1;
	char visit[MAX];
	char src, target, i, j;
	for(i=0; i<=nTask; i++){
		visit[i] = 0;
	}
	queue[0] = start;
	visit[target] = 1;
	while(head < tail){
		src = queue[head++];
		for(i=1; i<=task[src].degree; i++){
			target = task[src].neighbor[i];
			if(visit[target] == 0){
				visit[target] = 1;
				queue[tail++] = target;
			}
		}
	}
	return tail;
}

void solve(char nTask, struct Task task[]){
	char inDegree[MAX];
	char i, j, nDep, target, ans;
	for(i=1; i<=nTask; i++){
		inDegree[i] = 0;
	}
	for(i=1; i<=nTask; i++){
		for(j=1; j<=task[i].degree; j++){
			inDegree[task[i].neighbor[j]] += 1;
		}
	}
	ans = -1;
	for(i=1; i<=nTask; i++){
		if(inDegree[i] == 0){
			nDep = BFS(i, nTask, task);
			if(nDep > ans){
				ans = nDep;
				target = i;
			}
		}
	}
		
	/*printf("%hhd %hhd\n", target, ans);*/
	
	printf("%hhd\n", target);
}

int main(){
	char i, j;
	struct Task task[MAX];
	char nTask;
	FILE *fp = stdin;
	while(1 == fscanf(fp, "%hhd", &nTask)){
		if(0 == nTask) break;
		for(i=1; i<=nTask; i++){
			fscanf(fp, "%hhd", &task[i].degree);
			for(j=1; j<=task[i].degree; j++){
				fscanf(fp, "%hhd", &(task[i].neighbor[j]));
			}
			task[i].nDep = 0;
		}
		solve(nTask, task);
	}	
	return 0;
}
