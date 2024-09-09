#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8
#define NN 64
#define INF 10000
#define TRUE 1
#define FALSE 0

#define GET_COL(pos) ((pos) & 0x7)
#define GET_ROW(pos) ((pos) >> 3)
#define MIN(a, b) ((a) < (b)? (a) : (b))


int movable(short pos1, short pos2){
	/*pos is encoded, the least three significant bits represent column*/
	short r1, c1, r2, c2;
	short roffset, coffset;
	short tmp;
	
	r1 = GET_ROW(pos1);
	c1 = GET_COL(pos1);
	r2 = GET_ROW(pos2);
	c2 = GET_COL(pos2);
	roffset = abs(r1 - r2);
	coffset = abs(c1 - c2);
	if((roffset == 1) && (coffset == 2)) return TRUE;
	else if ((roffset == 2) && (coffset == 1)) return TRUE;
	else return FALSE;
}

void calcDist(short dist[NN][NN]){
	short i, j, k;


	for(i=0; i<NN; i++){
		for(j=0; j<i; j++){
			if(movable(i, j)){
				dist[i][j] = 1;
				dist[j][i] = 1;	
			} else {
				dist[i][j] = INF;
				dist[j][i] = INF;
			}
		}
		dist[i][i] = 0;
	}

#if 0
	for(i=0;i<NN;i++){
		for(j=0; j<NN; j++){
			if(dist[i][j] == INF) printf("X");
			else printf("%d", dist[i][j]);
		}
		printf("\n");
	}	
	#endif
	
	for(i=0; i<NN; i++){
		for(j=0; j<NN; j++){
			for(k=0; k<NN; k++){
				dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	#if 0
	for(i=0;i<NN;i++){
		for(j=0; j<NN; j++){
			if(dist[i][j] == INF) printf("X");
			else printf("%d", dist[i][j]);
		}
		printf("\n");
	}	
	#endif

}

int decodePos(char s[3]){
	int result;
	result = s[0] - 'a';
	result = (result << 3) + s[1] - '1';
	return result;
}

int main(){
	short dist[NN][NN];
	char fromPos[3], toPos[3];
	int cur, next;
	calcDist(dist);
	
	while(2 == scanf("%s %s", fromPos, toPos)){
		cur = decodePos(fromPos);
		next = decodePos(toPos);
		printf("To get from %s to %s takes %d knight moves.\n", fromPos, toPos, dist[cur][next]);		
	}
	
	return 0;
} 