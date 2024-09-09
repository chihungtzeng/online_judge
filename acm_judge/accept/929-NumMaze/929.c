#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>
#define DEBUG 1
#define MAXINT 10000000
#define MAXCOL 1000
/*
implment my own binary search tree
*/

struct element {
	struct element *forward;
	struct element *backward;
	int r;
	int c;
};

int compareInt(const void *x, const void *y){
	return (*(int *)x) - (*(int *)y);
}



struct element *new_element(int row,int col){
	struct element *e;
	e = (struct element *) malloc(sizeof(struct element));
	e->r = row;
	e->c = col;
	e->forward = NULL;
	e->backward = NULL;
	return e;
}

int main(){
	void *root = NULL;
	int nG,nRow,nCol;
	int **maze;
	int **cost;
	int ts;
	int i,j,k;
	int *key,*keyptr;
	int temp;
	int row,col,rt,ct;
	char *buf,ch;
	
	
	struct element *head,*tail,*target,*cur;
	FILE *fp;
	
	if(DEBUG){
		fp = fopen("in.txt","r");
	}
	else{
		fp = stdin;
	}
	buf = (char *) malloc(sizeof(char)*3*MAXCOL);
	
	

	fgets(buf,3*MAXCOL,fp);
	nG=atoi(buf);
	if(DEBUG) {printf("nG = %d\n",nG);}
	for(i=0;i<nG;i++){
		
		
		
		
		fscanf(fp,"%d %d",&nRow,&nCol);
		
		
		
		
		maze = (int **)malloc(sizeof(int *)*(nRow));
		cost = (int **)malloc(sizeof(int *)*(nRow));
		for(j=0;j<nRow;j++){
			maze[j] = (int *) malloc(sizeof(int)*(nCol));
			cost[j] = (int *) malloc(sizeof(int)*(nCol));
		}
		
		for(j=0;j<nRow;j++){
	/*		
			fgets(buf,3*MAXCOL,fp);
			ch = buf;
			for(k=0;k<nCol;k++){
				 while(*ch == ' '){
				 	ch++;
				 }
				 maze[j][k] = *ch - '0';
				 cost[j][k]=MAXINT;
				 ch++;
			}
	*/

			for(k=0;k<nCol;k++){
				fscanf(fp,"%[0-9]",&maze[j][k]);
				
				cost[j][k]=MAXINT;
			}
			
			
		}
		
		if(DEBUG){
			printf("nRow=%d nCol=%d\n",nRow,nCol);
			for(j=0;j<nRow;j++){
				for(k=0;k<nCol;k++){
					printf("%d ",maze[j][k]);
				}
				printf("\n");
			}
		}
		/*start calculating maze[i][j]
		for a cell (i,j), its key = i*nRow+j; 
		*/
		
		cost[0][0] = maze[0][0];
		head = new_element(0,0);
		tail = head;
		
		while(head != NULL){
			cur = head;
			row = head->r;
			col = head->c;
			key = (int *) malloc(sizeof(int));
			*key = row*MAXCOL+col;
			tdelete(key,&root,compareInt);
			free(key);

			if (DEBUG){
				printf("inspecting cell (%d %d)\n",row,col);
			}
			/*checing the four possibe directions*/
			rt = row;
			ct = col+1;
			
			if(ct < nCol){
				temp = cost[row][col] + maze[rt][ct];
				if(cost[rt][ct] > temp){
					
					cost[rt][ct] = temp;
					key = (int *) malloc(sizeof(int));
					*key = rt*MAXCOL+ct;
					keyptr = tsearch(key,&root,compareInt);
					if (key != *(int **)keyptr){
						/*key has already in the tree*/
						free(key);
					}
					else{
						target = new_element(rt,ct);
						insque(target,tail);
						tail = tail->forward;
					}
				}
			}
			rt = row;
			ct = col-1;
			
			if(ct >= 0){
				temp = cost[row][col] + maze[rt][ct];
				if(cost[rt][ct] > temp){
					
					cost[rt][ct] = temp;
					key = (int *) malloc(sizeof(int));
					*key = rt*MAXCOL+ct;
					keyptr = tsearch(key,&root,compareInt);
					if (key != *(int **)keyptr){
						/*key has already in the tree*/
						free(key);
					}
					else{
						target = new_element(rt,ct);
						insque(target,tail);
						tail = tail->forward;
					}
				}
			}
			rt = row+1;
			ct = col;
			
			if(rt < nRow){
				temp = cost[row][col] + maze[rt][ct];
				if(cost[rt][ct] > temp){
					
					cost[rt][ct] = temp;
					key = (int *) malloc(sizeof(int));
					*key = rt*MAXCOL+ct;
					keyptr = tsearch(key,&root,compareInt);
					if (key != *(int **)keyptr){
						/*key has already in the tree*/
						free(key);
					}
					else{
						target = new_element(rt,ct);
						insque(target,tail);
						tail = tail->forward;
					}
				}
			}
			rt = row-1;
			ct = col;
			
			if(rt >=0){
				temp = cost[row][col] + maze[rt][ct];
				if(cost[rt][ct] > temp){
					
					cost[rt][ct] = temp;
					key = (int *) malloc(sizeof(int));
					*key = rt*MAXCOL+ct;
					keyptr = tsearch(key,&root,compareInt);
					if (key != *(int **)keyptr){
						/*key has already in the tree*/
						free(key);
					}
					else{
						target = new_element(rt,ct);
						insque(target,tail);
						tail = tail->forward;
					}
				}
			}
			
			head = head->forward;
			remque(cur);
		}
		/*-------------------*/
		if(DEBUG){
			printf("nRow=%d nCol=%d\n",nRow,nCol);
			for(j=0;j<nRow;j++){
				for(k=0;k<nCol;k++){
					printf("%5d ",cost[j][k]);
				}
				printf("\n");
			}
		}		
		
		printf("%d\n",cost[nRow-1][nCol-1]);
		
		for(j=0;j<nRow;j++){
			free(maze[j]);
			free(cost[j]);
		}
		free(maze);
		free(cost);
	}

	return 0;
}
