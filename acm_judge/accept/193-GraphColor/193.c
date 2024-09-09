#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNV 101
#define UNDEF -1
#define WHITE 0
#define BLACK 1
#define DEBUG 0
#define READFILE 0
#define PRINT_PROGRESS 0

struct Node {
	int id,color;
	int *neighbor;
	int nNeighbor;
};
int count=0;

struct Edge {
	int id1,id2;
};

void printColor(struct Node *V, int nV){
	int i;
	for(i=0;i<nV;i++){
		printf("(%d, %d)",V[i].id, V[i].color);
	}
	printf("\n");
}

void printV(struct Node *V, int nV){
	int i,j;
	if (NULL == V) printf("NULL V\n");
	printf("Vertices = \n");
	for(i=0;i<nV;i++){
		printf("(%d, %d) ",V[i].id,V[i].color);
		for(j=0;j<V[i].nNeighbor;j++){
			printf("%d ",V[i].neighbor[j]);
		}
	}

	printf("\n");
}

void printE(struct Edge *E, int nE){
	int i;
	printf("E = ");
	for(i=0;i<nE;i++){
		printf("(%d, %d) ",E[i].id1, E[i].id2);
	}
	printf("\n");
}

int ifExist(int element, int *a,int na){
	int i;
	for(i=0;i<na;i++){
		if (a[i] == element) return 1;
	}
	return 0;
}

struct Node *copyV(struct Node *V, int nV){
	int i,j;
	struct Node *Vtmp;
	Vtmp = (struct Node *) malloc(sizeof(struct Node)*nV);
	for(i=0;i<nV;i++){
		Vtmp[i].id = V[i].id;
		Vtmp[i].color = V[i].color;
		Vtmp[i].nNeighbor = V[i].nNeighbor;
		Vtmp[i].neighbor = (int *) malloc(sizeof(int)*MAXNV);
		for(j=0;j<V[i].nNeighbor;j++){
			Vtmp[i].neighbor[j] = V[i].neighbor[j];
		}
	}
	return Vtmp;
}

struct Node *removeNode(struct Node *V, int nV, int v){
/*return V-{v}*/
	int i,j,itmp,nn;
	struct Node *Vtmp;
	
	Vtmp = (struct Node *) malloc(sizeof(struct Node)*(nV-1));
	itmp=0;
	for(i=0;i<nV;i++){
		if(V[i].id != v){
			Vtmp[itmp].id = V[i].id;
			Vtmp[itmp].color = V[i].color;
			Vtmp[itmp].neighbor = (int *) malloc(sizeof(int)*MAXNV);
			Vtmp[itmp].nNeighbor = 0;
			nn=0;
			for(j=0;j<V[i].nNeighbor;j++){
				if(V[i].neighbor[j] != v){
					Vtmp[itmp].neighbor[nn] = V[i].neighbor[j];
					nn++;
				}
			}
			Vtmp[itmp].nNeighbor = nn;
			itmp++;
		}
	}
	return Vtmp;
}
void assignColor(struct Node *V, int nV, int target, int c){
	int i;
	for(i=0;i<nV;i++){
		if (V[i].id == target){
			V[i].color = c;
			return ;
		}
	}
	printf("Node %d does not exist\n",target);
	return;
}

void freeGraph(struct Node *Vin, int nV){
	int i;
	if (NULL == Vin) return;
	for(i=0;i<nV;i++){
		free(Vin[i].neighbor);
	}
	free(Vin);
}

struct Node *findMI(struct Node *V, int nV){
	int i,j;
	struct Node *Vtmp1, *Vtmp2;
	struct Node *V1, *V2;
	struct Node *V_v0, *V_vi;
	int nV_v0, nV_vi;
	int idtmp,ctmp;
	int sum1=0,sum2=0;
	if (0 == nV){
		return NULL;
	}
	if (NULL == V){
		printf("NULL V!\n");
		return NULL;
	}
	if (V[0].color != UNDEF){
		printf("Wrong Recursion!\n");
		return NULL;
	}
	/*make a carbon copy of V; it will be used in case 2*/
	V1 = copyV(V, nV);
	V2 = copyV(V, nV);
	if(PRINT_PROGRESS){
		printf("call function findMI %d times\n",count);
		count++;
		printf("call function findMI with %d vertices\n",nV);
		getchar();
	}	
	
	if(DEBUG){
		printf("start to call findMI()\n");
		printV(V1, nV);
		printV(V2, nV);
		getchar();
	}
	
	/*		Case 1: V[0] is colored by BLACK	*/
	if(PRINT_PROGRESS){
		printf("start case 1\n");
	}	
	
	assignColor(V1, nV, V1[0].id, BLACK);	
	V_vi = removeNode(V1, nV, V1[0].id);
	for(i=0;i<V1[0].nNeighbor;i++){
		assignColor(V1,nV,V1[0].neighbor[i],WHITE);
		Vtmp1 = V_vi;
		V_vi = removeNode(V_vi, nV-i-1, V1[0].neighbor[i]);
		
		freeGraph(Vtmp1,nV-i-1);
	}
	nV_vi = nV - 1 - V1[0].nNeighbor;
	Vtmp1 = findMI(V_vi, nV_vi);
	for(i=0;i<nV_vi;i++){
		idtmp = Vtmp1[i].id;
		ctmp = Vtmp1[i].color;
		assignColor(V1,nV,idtmp,ctmp);
	}
	freeGraph(Vtmp1,nV_vi);
	freeGraph(V_vi,nV_vi);
	for(i=0;i<nV;i++){
		if(V1[i].color == BLACK){
			sum1++;
		}
		if(V1[i].color == UNDEF){
			printf("V1 has undefined color\n");
		}
	}
	
	if(DEBUG){
		printColor(V1,nV);
		getchar();
	}
	
	
	/*		Case 2: V[0] is colored by WHITE
			
	*/
	if(PRINT_PROGRESS){
		printf("start case 2\n");
	}	
	V2[0].color = WHITE;
	V_v0 = removeNode(V2, nV, V2[0].id);
	Vtmp2=findMI(V_v0,nV-1);
	for(i=0;i<nV-1;i++){
		idtmp = Vtmp2[i].id;
		ctmp = Vtmp2[i].color;
		assignColor(V2,nV,idtmp,ctmp);
	}	 
	for(i=0;i<nV;i++){
		if(V2[i].color == BLACK){
			sum2++;
		}
		if(V2[i].color == UNDEF){
			printf("V2 has undefined color\n");
		}
	}
	freeGraph(V_v0,nV-1);
	freeGraph(Vtmp2,nV-1);

	if(PRINT_PROGRESS){
		printf("start summing up result\n");
	}	
	if(DEBUG){
		printColor(V2,nV);
		getchar();
	}
	if(sum1 >= sum2){
		freeGraph(V2,nV);
		return V1;
	}

	freeGraph(V1,nV);
	return V2;

	
}



int main(){
	int max;
	struct Node *V,*Vans;
	FILE *fp;
	
	int nG, nE, nV;
	int i,j;
	int id1,id2;
	int nMI;
	int head;	
	
	if(READFILE){
		fp=fopen("input.txt","r");
		if (NULL == fp){
			printf("open file failed \n");
		}
		fscanf(fp,"%d",&nG);
	}
	else{
		scanf("%d",&nG);
	}
	
	
	for(i=0;i<nG;i++){
		count=0;
		if(READFILE){
			fscanf(fp,"%d %d",&nV, &nE);
		}
		else{
			scanf("%d %d",&nV, &nE);
		}
		if (DEBUG){
		
			printf("read No.%d graph\n",i);
		}
		V = (struct Node *) malloc(sizeof(struct Node)*MAXNV);
		
				
		for(j=0;j<nV;j++){
			V[j].id = j+1;
			V[j].color = UNDEF;
			V[j].neighbor = (int *) malloc(sizeof(int)*MAXNV);
			V[j].nNeighbor = 0;
		}
		for(j=0;j<nE;j++){
			if(READFILE){
				fscanf(fp,"%d %d",&id1, &id2);
			}
			else{
				scanf("%d %d",&id1, &id2);
			}
			if (id1 != id2) {		
				if(!ifExist(id2, V[id1-1].neighbor, V[id1-1].nNeighbor)){
					V[id1-1].neighbor[V[id1-1].nNeighbor] = id2;
					V[id1-1].nNeighbor++;
				}
				if(!ifExist(id1, V[id2-1].neighbor, V[id2-1].nNeighbor)){
					V[id2-1].neighbor[V[id2-1].nNeighbor] = id1;
					V[id2-1].nNeighbor++;
				}
			}
		}
		if(PRINT_PROGRESS){
			printf("read %d nodes and %d vertices\n",nV,nE);
		}

		if(DEBUG){
			printV(V,nV);
		}
		Vans=findMI(V,nV);
		nMI=0;
		for(j=0;j<nV;j++){
			if(Vans[j].color == BLACK){
				nMI++;
			}
			if(Vans[j].color == UNDEF){
				printf("undefined color detected\n for node %d",Vans[j].id);
			}
		}		
		
		printf("%d\n",nMI);
		head=0;
		for(j=0;j<nV;j++){
			
			if(Vans[j].color == BLACK){
				if(head == 1){
					printf(" ");
				}
				printf("%d",V[j].id);
				head=1;
			}
		}
		printf("\n");
		freeGraph(V,nV);	
	}

	exit(0);
}