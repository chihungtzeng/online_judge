#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXROW 10
#define MAXCOL 100
#define DEBUG 0

void printMatrix(long int **matrix,int nRow,int nCol){
	int i,j;
	for(i=0;i<nRow;i++){
		for(j=0;j<nCol;j++){
			printf("%ld ",matrix[i][j]);
		}
		printf("\n");
	}
}
void printPath(long int *p,int nCol){
	int i;
	for(i=0;i<nCol-1;i++){
		printf("%ld ",p[i]);
	}
	printf("%ld\n",p[nCol-1]);
}

void find_path(long int *p,long  int **cost,int nRow, int nCol, int endRow){
	int i,j,candidate;
	int cur,frm,to;
	int min;
	p[nCol-1]=endRow;
	to = endRow;
	for(j=nCol-2;j>=0;j--){

		frm = to;
		
		candidate = (to+1)%nRow ;
		if (cost[frm][j] == cost[candidate][j]){
			frm = (frm<candidate)? frm: candidate;
		} 
		if (cost[frm][j] > cost[candidate][j]){
			frm = candidate;
		} 
		candidate = (nRow - 1 + to) % nRow;
		if (cost[frm][j] == cost[candidate][j]){
			frm = (frm<candidate)? frm: candidate;
		} 
		if (cost[frm][j] > cost[candidate][j]){
			frm = candidate;
		}
		
		p[j]=frm;
		to=frm;
	}
	if(DEBUG){
		printPath(p,nCol);
	}

}

int comparePath(long int *pa,long  int *pb, int nCol){
	int i;
	for(i=0;i<nCol;i++){
		if(pa[i]<pb[i]) return -1;
		if(pa[i]>pb[i]) return 1;
	}
	return 0;
}

void find_ans(long int **matrix, int nRow, int nCol){
	int i,j,tmpi;
	int x;
	long int **cost;
	long int *path,*tmp_path;
	int start, end;
	
	cost = (long int **) malloc(sizeof(long int *)*nRow);
	path = (long int *) malloc(sizeof(long int *)*nCol);
	tmp_path = (long int *) malloc(sizeof(long int *)*nCol);	
	path[0] = 1000000;
	
	for(i=0;i<nRow;i++){
		cost[i] = (long int *) malloc(sizeof(long int *)*nCol);
		cost[i][0] = matrix[i][0];
	}
	
	for(j=1;j<nCol;j++){
		for(i=0;i<nRow;i++){

			x = cost[i][j-1];
			if (x > cost[(i+1)%nRow][j-1]){
				x = cost[(i+1)%nRow][j-1];
			}
			if (x > cost[(nRow+i-1)%nRow][j-1]){
				x = cost[(nRow+i-1)%nRow][j-1];
			}
			cost[i][j] = x + matrix[i][j];
		}
	}
	
	if(DEBUG) {printMatrix(cost,nRow,nCol);}
	
	x = cost[0][nCol-1];
	for(i=1;i<nRow;i++){
		if (x > cost[i][nCol-1]){
			x = cost[i][nCol-1];			
		}
	}
	for(i=0;i<nRow;i++){
		if(x == cost[i][nCol-1]){

			find_path(tmp_path,cost,nRow,nCol,i);

			if(comparePath(tmp_path,path,nCol)<0){
				for(j=0;j<nCol;j++){
					path[j] = tmp_path[j];
				}
			}
		}
	}

	for(i=0;i<nCol-1;i++){
		printf("%ld ",path[i]+1);
	}
	printf("%ld\n",path[nCol-1]+1);
	printf("%d\n",x);
	for(i=0;i<nRow;i++){
		free(cost[i]);
	}

	free(cost);
}

int main(int argc,char *argv[]){
	char *line;
	int nRow,nCol;
	
	int i,j;
	long int **matrix;
	
	
	while(2 == scanf("%d %d",&nRow,&nCol)){
		
		matrix = (long int **) malloc(sizeof(long int *)*nRow);
		
		for(i=0;i<nRow;i++){
			matrix[i] = (long int *) malloc(sizeof(long int)*nCol);
			for(j=0;j<nCol;j++){
				scanf("%ld",&matrix[i][j]);
			}
		}
		
		find_ans(matrix,nRow,nCol);
		for(i=0;i<nRow;i++){
			free(matrix[i]);
		}
		free(matrix);
	}
	exit(0);
}
