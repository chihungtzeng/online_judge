#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define DEBUG 0
#define MAX 8196




void *root;
long *humble;
int nHumble;
int pos = 0;

int compareLong(const void *a, const void *b){
	return *(long *)a - *(long *)b;
}

long *newLong(long x){
	long *p;
	p = (long *) malloc(sizeof(long));
	*p = x;
	return p;
}

void genHumble(){
	long *seq[2];
	long *gen, *newHumble, *tmp;
	long nGen, *p, count, *match, i, j, shit;
	long multiple[4] = {2, 3, 5, 7};	
	

	seq[0] = (long *)malloc(sizeof(long)*MAX);
	seq[1] = (long *)malloc(sizeof(long)*MAX);
	
	root = NULL;
	p = newLong(1);
	tsearch(p, &root, compareLong);
	
	gen = seq[0];
	newHumble = seq[1];
	gen[0] = 1;
	nGen = 1;	
	nHumble = 1;
	
	while(nGen >0){
		count = 0;
		for(i=0; i<nGen; i++){
			
			for(j=0; j<4; j++){
				shit = gen[i]*multiple[j];
				if(shit > 2000000000){
					continue;
				}
				
				p = newLong(shit);
				match = tsearch(p, &root, compareLong);
				if(!match) {
					printf("No sufficient memory\n");
				}
				else if ((*(long **)match) != p){
					free(p);
				}
				else{
					newHumble[count++] = *p;
					nHumble++;
				}
			}
		}
		tmp = newHumble;
		newHumble = gen;
		gen = tmp;
		nGen = count;
	}
	free(newHumble);
	free(gen);
}

void twalkAction(const void *rootp, const VISIT which, const int depth){
	if( ((which == postorder) || (which == leaf)) && (pos < MAX)){
		humble[pos++] = **(long **)rootp;
	}
}

int main(){
	int k;
	long ans;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in3.txt","r") : stdin;
	humble = (long *) malloc(sizeof(long)*MAX);
	genHumble();	
	pos = 0;
	twalk(root, twalkAction);
	tdestroy(root, free);
	while(1 == fscanf(fp,"%d",&k)){
		ans = humble[k-1];
		if(k == 0){
			break;
		}
		else if((k % 10 == 1) && (k % 100 != 11)){
			printf("The %dst humble number is %ld.\n", k, ans);
		}
		else if((k % 10 == 2) && (k % 100 != 12)){
			printf("The %dnd humble number is %ld.\n",k,ans);
		}
		else if ((k %10 == 3) && (k % 100 != 13)){
			printf("The %drd humble number is %ld.\n",k,ans);
		}
		else{
			
			printf("The %dth humble number is %ld.\n", k, ans);
		}
	}
	
	free(humble);
	return 0;	
}