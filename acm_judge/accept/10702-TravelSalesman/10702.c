#include <stdio.h>
#include <string.h>
#define MAX 128
#define MAXINTER 1024
#define DEBUG 0

short C, S, E, T; /*C: city, S:start city, T:#inter city, E:#end city*/
short endCity[MAX];
int cost[MAX][MAX];
int curCost[MAXINTER][MAX];


void findAns(){
	short i, j, dest, src;
	short step, preStep;
	int max;
	
	for(i=1; i<=C; i++){
		curCost[1][i] = cost[S][i];
	}
	curCost[1][S] = -10000;
	
	for(step = 2; step <= T; step++){
		preStep = step - 1;
		for(dest=1; dest<=C; dest++){
			max = 0;
			for(src=1; src<=C; src++){
				if((dest != src) && (curCost[preStep][src] + cost[src][dest] > max)){
					max = curCost[preStep][src] + cost[src][dest];
				}
			}
			curCost[step][dest] = max;
		}
	}

	if(DEBUG){
		for(i=1; i<=T; i++){
			for(j=1; j<=C; j++){
				printf("%5d ", curCost[i][j]);
			}
			printf("\n");
		}
	}	
	
	max = -1;
	for(i=1; i<=E; i++){
		dest = endCity[i];
		if(curCost[T][dest] > max){
			max = curCost[T][dest];
		}
	}
	printf("%d\n",max);
}

int main(){
	short i, j;

	while(4 == scanf("%hd %hd %hd %hd", &C, &S, &E, &T)){
		if((C == 0) && (S == 0) && (E == 0) && (T == 0)){
			break;
		}
		for(i=1; i<=C; i++){
			for(j=1; j<=C; j++){
				scanf("%d",&cost[i][j]);
			}
		}
		for(i=1; i<=E; i++){
			scanf("%hd", &endCity[i]);
		}
		findAns();
	}

	return 0;
}
