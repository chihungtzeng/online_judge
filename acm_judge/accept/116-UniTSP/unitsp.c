#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXROW 10
#define MAXCOL 100
#define DEBUG 0

void printMatrix(int **matrix,int nRow,int nCol){
	int i,j;
	for(i=0;i<nRow;i++){
		for(j=0;j<nCol;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
void printPath(int *p,int nCol){
	int i;
	for(i=0;i<nCol;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}

void find_path(int *p, int **cost,int nRow, int nCol, int endRow){
	int i,j,candidate;
	int cur,frm,to;
	int min;
	p[nCol-1]=endRow;
	to = endRow;
	for(j=nCol-2;j>=0;j--){
		//from must be one of (i-1,j-1) (i,j-1), (i+1,j-1)
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

int comparePath(int *pa, int *pb, int nCol){
	//if pa<pb (lexicographically) return -1
	//if pa=pb return 0
	//otherwise 1
	int i;
	for(i=0;i<nCol;i++){
		if(pa[i]<pb[i]) return -1;
		if(pa[i]>pb[i]) return 1;
	}
	return 0;
}

void find_ans(int **matrix, int nRow, int nCol){
	int i,j,tmpi;
	int x;
	int **cost;
	int *path,*tmp_path;
	int start, end;
	
	cost = (int **) malloc(sizeof(int *)*nRow);
	path = (int *) malloc(sizeof(int *)*nCol);
	tmp_path = (int *) malloc(sizeof(int *)*nCol);	
	path[0] = 1000000;
	
	for(i=0;i<nRow;i++){
		cost[i] = (int *) malloc(sizeof(int *)*nCol);
		cost[i][0] = matrix[i][0];
	}
	
	for(j=1;j<nCol;j++){
		for(i=0;i<nRow;i++){
			// x = min(cost[i-1][j-1], cost[i][j-1], cost[i+1][j-1])
			// cost[i][j] = x + matrix[i][j]
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

	for(i=0;i<nCol;i++){
		printf("%d ",path[i]+1);
	}
	printf("\n");
	printf("%d\n",x);
	for(i=0;i<nRow;i++){
		free(cost[i]);
	}

	free(cost);
}

int main(int argc,char *argv[]){
	char *line;
	int nRow,nCol;
	FILE *fp;
	int i,j;
	int **matrix;
	
	fp = fopen("input.txt","r");
	line = (char *) malloc(sizeof(char)*1024);
	
	while(EOF != fscanf(fp,"%d %d",&nRow,&nCol)){
		//nCol = fscanf(fp,"%d",&nCol);
		matrix = (int **) malloc(sizeof(int *)*nRow);
		//printf("row=%d, col=%d\n",nRow,nCol);
		for(i=0;i<nRow;i++){
			matrix[i] = (int *) malloc(sizeof(int)*nCol);
			for(j=0;j<nCol;j++){
				fscanf(fp,"%d",&matrix[i][j]);
			//	printf("%d ",matrix[i][j]);
			}
		}
		//printMatrix(matrix,nRow,nCol);
		find_ans(matrix,nRow,nCol);
		for(i=0;i<nRow;i++){
			free(matrix[i]);
		}
		free(matrix);
	}
}
