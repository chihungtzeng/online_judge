#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LINELEN 1024
#define NBOX 30
#define DEBUG 0



struct Box {
	int dim;
	int *w; /*width for each dimension*/
};

int compareInt(const void *a, const void *b){
	/* a<b, a==b, a>b return -1, 0, 1 respectively*/ 
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1; 
}
int compareBox(struct Box a, struct Box b){
	/*
	if box a can be put into box b, return -1 (a<b)
	if box b can be put into box a, return 1 (a>b)
	otherwise return 0;
	*/
	int i,result;
	int equal=0,less=0,more=0;
	for (i=0;i<a.dim;i++){
		if (a.w[i] < b.w[i]){ less+=1;}
		if (a.w[i] == b.w[i]) {equal+=1;}
		if (a.w[i] > b.w[i]){ more+=1;}
	}
	
	if (less == a.dim) return -1;
	if (more == a.dim) return 1;
	return 0;
}

int *toposort(struct Box *box, int k){
	int mark[NBOX], *toporank;
	int i,j;
	int is_sink;
	int done,rank;
	memset(mark,-1,sizeof(mark));
	/*keeping find the set of source*/
	done=0;
	toporank=(int *) malloc(sizeof(int)*NBOX);
	rank=0;
	while(!done){
		/*recursively find a set of sinks and give them ranks*/
		for(i=0;i<k;i++){
			/*those sinks are first marked with 0
			mark[i]=-1 : box i has not been assigned a rank
			mark[i]=0: box i is determined to be a sink, ready to give it a rank
			mark[i]=1: box i can be considered to be removed
			*/
			 
			if (-1 == mark[i]){
				is_sink=1;				
				for(j=0; (j<k)&&(is_sink); j++){
					/*
					if box[i]>box[j] then box[i] is not a sink
					we only consider boxes with mark=0 or -1
					*/
					if ((i!= j) && (0 >= mark[j]) && (compareBox(box[i],box[j])==1) ){
						is_sink=0;
					}
				}
				if (is_sink){
					mark[i] = 0;
				}
			}
		}
		for(i=0;i<k;i++){
			if(0 == mark[i]){
				mark[i] = 1;
				toporank[rank] = i;
				rank++;
			}
		}
		/*if some mark is -1, done=0;*/
		done=1;
		for(i=0;i<k;i++){
			if (-1 == mark[i]) done=0;
		}
	}

	if(DEBUG){
		for(i=0;i<k;i++){
			printf("%d ",toporank[i]);
		}
		printf("\n");
		getchar();
	}	
	
	return toporank;
}

void printBox(struct Box *b){
	int i;
	printf("(");
	for(i=0;i< b->dim; i++){
		printf("%d,",b->w[i]);
	}
	printf(")\n");
}
void box_setup(struct Box *b, int d, char *width){
	int i;
	b->dim = d;
	
	if(b->w != NULL){
		free(b->w);
	}
	b->w = (int *) malloc(sizeof(int)*d);
	b->w[0] = atoi(strtok(width," "));
	
	for(i=1;i<d;i++){
		b->w[i] = atoi( strtok(NULL," "));	
	}
	qsort(b->w,d,sizeof(int),compareInt);
	if (DEBUG) printBox(b);
}

int main(int argc, char *argv[]){
	FILE *fp;
	char *line;
	char *k_dim;
	int k, d;
	int i,j,max;
	struct Box *box;
	int *toporank, length[NBOX], pre[NBOX],output[NBOX];
	int current,target,predecessor,head;  
	
	/*fp = fopen("input.txt","r");*/
	fp = stdin;
	if (NULL == fp){
		printf("Open file failed");
		exit(EXIT_FAILURE);
	}
	
	k_dim = (char *) malloc(sizeof(char)*LINELEN);
	line = (char *) malloc(sizeof(char)*LINELEN);
	box = (struct Box *) malloc(sizeof(struct Box)*NBOX);
	
	while(NULL != fgets(k_dim,LINELEN,fp)) {
		
		memset(length,0,sizeof(length));
		memset(pre,-1,sizeof(pre));
		
		
		k = atoi(strtok(k_dim," "));
		d = atoi(strtok(NULL," "));
		for (i=0;i<k;i++){
			fgets(line,LINELEN,fp);
			box_setup(&box[i],d,line);
		}
		/*topological sort*/
		toporank = toposort(box,k);
		/*decide the lengths of the topology and the predecedor for each box*/

		for(i=0;i<k;i++){

			current = toporank[i];
			max=0;
			predecessor=-1;
			for(j=0;j<i;j++){
				target=toporank[j];
				if ( (compareBox(box[current],box[target]) == 1) &&
						(max < length[target])
					){
					max = length[target];
					predecessor = target; 
				}
			}
			length[current] = max+1;
			pre[current] = predecessor;
		}
		max=0;
		for(i=0;i<k;i++){
			if (max < length[i]){
				max = length[i];
				head = i; 
			}
		}
		printf("%d\n",max);
		j=0;
		while(head != -1){
			output[j] = head+1;
			j++;
			head=pre[head];
		}
		printf("%d",output[j-1]);
		for(i=j-2;i>=0;i--){
			printf(" %d",output[i]);
		}
				
		printf("\n");
		
	}
	
	return 0;
}
