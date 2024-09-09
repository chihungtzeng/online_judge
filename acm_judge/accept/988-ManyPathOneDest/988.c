#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15000
#define DEBUG 0

struct mevent{
	int nPath;
	int nSuccessor;
	int *successor;
	int id;
};

struct qele {
	struct qele *next;
	int id;
};

struct qele *q_insert(struct qele *tail, int id){
	struct qele *e;

	e = (struct qele *) malloc(sizeof(struct qele));
	e->next = NULL;
	e->id = id;
	if(NULL == tail){
		 return e;
	}
	else{
		tail->next = e;
	}
	return e;
}

int find_ans(struct mevent *elist, int nEvent){
	int indeg[nEvent];
	int topo[nEvent];
	int mark[nEvent];
	int nMark;
	int i,j,idx;
	int src, dest;
	int ans;
	struct qele *head, *tail, *target;
	
	head = NULL;
	tail = NULL;
	nMark=0;


	memset(indeg,0,sizeof(int)*nEvent);
	for(i=0;i<nEvent;i++){
		for(j=0;j<elist[i].nSuccessor;j++){
			idx = elist[i].successor[j];
			indeg[idx]++;
		}
		/*we only sum nPath over the marked nodes */
		if(0 == elist[i].nSuccessor){
			mark[nMark] = i;
			nMark++;
		}
	}
	/*topo sort*/
	for(i=0;i<nEvent;i++){
		if(0 == indeg[i]){
			tail = q_insert(tail,i);
		}
		if(NULL == head){
			head = tail;
		}
	}
	
	for(i=0;i<nEvent;i++){
		target = head;
		idx = target->id;
		topo[i] = idx;
		for(j=0;j<elist[idx].nSuccessor;j++){
			dest = elist[idx].successor[j];
			indeg[dest]--;
			if(0 == indeg[dest]){
				tail = q_insert(tail,dest);
			}
		}
		head = head->next;
		free(target);
	}
	
	if(DEBUG){
		printf("--- result of topological sort ---\n");
		for(i=0;i<nEvent;i++){
			printf("%d ",topo[i]);
		}
		printf("\n");
	}
	
	for(i=0;i<nEvent;i++){
		src = i;
		for(j=0;j<elist[i].nSuccessor;j++){	
			dest = elist[src].successor[j];
			elist[dest].nPath = elist[dest].nPath + elist[src].nPath; 
		}
	}
	ans = 0;
	for(i=0;i<nMark;i++){
		dest = mark[i];
		ans = ans+ elist[dest].nPath;
	}
	return ans;
}



int main(){
	int nEvent;
	struct mevent *elist;
	int nS, i, j,tmp, ans,firstTest;
	FILE *fp;
	
	
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;
	firstTest = 1;
	while(1 == fscanf(fp,"%d",&nEvent)){
		if(!firstTest){
			printf("\n");
		}
		else{
			firstTest=0;
		}
		elist = (struct mevent *) malloc(sizeof(struct mevent)*nEvent);
		for(i=0;i<nEvent;i++){
			fscanf(fp,"%d",&nS);
			elist[i].successor = (int *) malloc(sizeof(int)*nS); 			
			elist[i].nPath=0;
			elist[i].id = i;
			elist[i].nSuccessor = nS;
			for(j=0;j<nS;j++){
				fscanf(fp,"%d",&tmp);
				elist[i].successor[j] = tmp; 
			}
		}
		elist[0].nPath=1;
		
		if(DEBUG){
			for(i=0;i<nEvent;i++){
				printf("%d: ",i);
				for(j=0;j<elist[i].nSuccessor;j++){
					printf("%d ", elist[i].successor[j]); 
				}
				printf("\n");
			}
		}
		
		/*ans = find_ans(elist, nEvent);*/
		ans = find_ans(elist, nEvent);
		printf("%d\n",ans);
		
		/*release memory*/
		for(i=0;i<nEvent;i++){
			free(elist[i].successor);
		}
		free(elist);
	} 	
		
	return 0;
}