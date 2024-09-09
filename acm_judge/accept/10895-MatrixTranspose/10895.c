#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define LEN 80
#define MAX_ROW 10005

struct Ele {
	int row;
	int col;
	int value;
};


int nRow, nCol;
void *row[MAX_ROW], *match;
int *totalEle;
int *out;
int nOut;


void initMatrix(int r){
	while(r >= 1){
		row[r] = NULL;
		totalEle[r] = 0;
		r--; 
	}
}

void destroyMatrix(int r){
	while(r >= 1){
		tdestroy(row[r], free);
		r--; 
	}
}

void printCol(const void *rootp, const VISIT way, const int depth){
	struct Ele *e;
	if((way == leaf) || (way == postorder)){
		e = *(struct Ele **)rootp;
		printf(" %d", e->col);
	}
}

void printValueToOut(const void *rootp, const VISIT way, const int depth){
	struct Ele *e;
	if((way == leaf) || (way == postorder)){
		e = *(struct Ele **)rootp;
		out[nOut++] = e->value;
	}
}

struct Ele *newEle(int r, int c){
	struct Ele *e;
	e = (struct Ele *) malloc(sizeof(struct Ele));
	e->row = r;
	e->col = c;
	return e;
}

int compareEle(const void *a, const void *b){
	struct Ele *x, *y;
	x = (struct Ele *)a;
	y = (struct Ele *)b;
	return x->col - y->col;
}



int main(){
	struct Ele *e[LEN];
	int i, nEle, r, c;
	char line[LEN], valueLine[LEN];
	FILE *fp  = stdin;
	totalEle = (int *) malloc(sizeof(int)*MAX_ROW);
	
	
	while(NULL != fgets(line, LEN, fp)){
		sscanf(line, "%d %d", &nRow, &nCol);
		initMatrix(nCol);
		for(r=1; r <= nRow; r++){
			fgets(line, LEN, fp);
			fgets(valueLine, LEN, fp);
			nEle = atoi(strtok(line, " \n"));
			for(i=1; i<=nEle; i++){
				c = atoi(strtok(NULL, " \n"));
				e[i] = newEle(c, r);
			}
			if(nEle >= 1){
				e[1]->value = atoi(strtok(valueLine, " \n"));
			}
			for(i=2; i<=nEle; i++){
				e[i]->value = atoi(strtok(NULL, " \n"));
			}
			for(i=1; i<=nEle; i++){
				tsearch(e[i], &row[e[i]->row], compareEle);
				totalEle[e[i]->row] += 1;
			}
		}
		printf("%d %d\n", nCol, nRow);
		for(r=1; r<=nCol; r++){
			printf("%d", totalEle[r]);			
			twalk(row[r], printCol);
			printf("\n");
			
			out = (int *) malloc(sizeof(int)*totalEle[r]);
			nOut = 0;
			
			twalk(row[r], printValueToOut);
			if(nOut > 0){
				printf("%d", out[0]);
				for(i=1; i<nOut; i++){
					printf(" %d", out[i]);
				}
			}
			printf("\n");
			free(out);
		}
		destroyMatrix(nCol);
	}
	free(totalEle);
	return 0;			
}