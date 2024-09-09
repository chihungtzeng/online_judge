#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0

int mymax(unsigned int a,unsigned int b){
	if (a > b) return a;
	else return b;
}

int mymin(unsigned int a, unsigned int b){
	if (a > b) return b;
	else return a;
}

int overlap(unsigned int a, unsigned int b, unsigned int x, unsigned int y){
/*
	overlap:
		a < x < b < y
		a < x < y < b 
		x < a < y < b
		x < a < b < y
*/
	if (a < x){
		if(((x < b) && (b < y)|| (y < b))) return 1;
		else return 0;
	}
	else {
		if( ((a < y) && (y < b)) || (b < y) ) return 1;
		else return 0;
	}

}

int main(){
	unsigned int *X1, *Y1, *X2, *Y2;
	int nTest;
	int nRect;
	int i,j; 
	unsigned int x1,x2,y1,y2;
	int conflict, dim2;
	
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d",&nRect);
		X1 = (unsigned int *) malloc(sizeof(unsigned int)*nRect);
		Y1 = (unsigned int *) malloc(sizeof(unsigned int)*nRect);
		X2 = (unsigned int *) malloc(sizeof(unsigned int)*nRect);
		Y2 = (unsigned int *) malloc(sizeof(unsigned int)*nRect);
		
		for(i=0;i<nRect;i++){
			/*(X1,Y1) is bottom-left, (X2,Y2) is upper-right*/
			scanf("%d %d %d %d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
			/*
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			X1[i] = mymin(x1,x2);
			X2[i] = mymax(x1,x2);
			Y1[i] = mymin(y1,y2);
			Y2[i] = mymax(y1,y2);
			*/
		}
		dim2 = 0;
		for(i=0; (i<nRect) && (!dim2);i++){
			if (Y1[i] != Y2[i]){
				dim2 = 1;
			}
		}
		
		if(DEBUG){
			printf("\n");
		}
		conflict = 0;
		if (dim2 == 1){
			for(i=0;i<nRect;i++){
				if (DEBUG) {printf("%d %d %d %d\n",X1[i], Y1[i], X2[i], Y2[i]);}
				for(j=i+1;j<nRect;j++){
					conflict = conflict | (overlap(X1[i],X2[i],X1[j],X2[j]) & overlap(Y1[i],Y2[i],Y1[j],Y2[j]));
				}
			}		
		}
		else{
			for(i=0;i<nRect;i++){
				if(DEBUG) {printf("%d %d %d %d\n",X1[i], Y1[i], X2[i], Y2[i]);}
				for(j = i + 1; j < nRect; j++){
					conflict = conflict | overlap(X1[i],X2[i],X1[j],X2[j]);
				}
			}
		}
		if(conflict){
			printf("Difficult problem(s)\n");
		}
		else{
			printf("No problem\n");
		}
		
		free(X1);
		free(X2);
		free(Y1);
		free(Y2);
	}	 
		
	
	return 0;
}