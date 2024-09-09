#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOK_NUM 5001
#define TRUE 1
#define FALSE 0
#define SWAP(a, b) (a) = (a) ^ (b); (b) = (a) ^ (b); (a) = (a) ^ (b)

struct Point {
	short x, y;
};

struct Rook {
	struct Point topLeft, bottomRight;
	struct Point range;
	struct Point pos;
};

int withinRange(short query, short left, short right){
	if(left > right){
		SWAP(left, right);
	}
	if((query < left) || (query > right)) return FALSE;
	else return TRUE;
}

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int isConnected(short start, short end, short occr[]){
	/*
		if each element in occr[start..end] >= 1 return true,
		otherwise false
	*/
	while(start <= end){
		if(occr[start] == 0) return FALSE;
		start++; 
	}
	return TRUE;
}

int decidePos(short pos[], short nRook, struct Point segment[]){
	short occr[nRook + 1];
	short i, j;
	short curPos = 1;
	memset(occr, 0, sizeof(occr));
	for(i=1; i<=nRook; i++){
		for(j=segment[i].x; j<=segment[i].y; j++){
			occr[j] += 1;
		}
	}

	do{
		if(isConnected(curPos, nRook, occr) == FALSE){
			return EXIT_FAILURE;
		}
	} while(	curPos <= nRook);
	return EXIT_SUCCESS;
}

int solve(short nRook, struct Rook rook[]){
	struct Point segment[nRook + 1];
	short pos[nRook + 1];
	int status;
	short i;
	/*decide x for each rook*/
	for(i=1; i <= nRook; i++){
		segment[i].x = rook[i].topLeft.x;
		segment[i].y = rook[i].bottomRight.x;
	}
	status = decidePos(pos, nRook, segment);
	if(status == EXIT_FAILURE){
		return EXIT_FAILURE;
	}
	/*decide y for each rook*/
	for(i=1; i <= nRook; i++){
		rook[i].pos.x = pos[i];
		segment[i].x = rook[i].topLeft.y;
		segment[i].y = rook[i].bottomRight.y;
	}
	status = decidePos(pos, nRook, segment);
	if(status == EXIT_FAILURE){
		return EXIT_FAILURE;
	}
	for(i=1; i <= nRook; i++){
		rook[i].pos.x = pos[i];
	}
	return EXIT_SUCCESS;
}

int main(){
	struct Rook rook[MAX_ROOK_NUM];
	int status;
	short nRook, i;
	FILE *fp = stdin;
	while(1 == fscanf(fp, "%hd", &nRook)){
		if(nRook == 0) break;
		for(i=1; i<=nRook; i++){
			fscanf(fp, "%hd %hd %hd %hd", 
				&(rook[i].topLeft.x), &(rook[i].topLeft.y),
				&(rook[i].bottomRight.x), &(rook[i].bottomRight.y));
		}
		status = solve(nRook, rook);
		if(status == EXIT_FAILURE){
			puts("IMPOSSIBLE");
		} else{	
			for(i=1; i<=nRook; i++){
				printf("%hd %hd\n", rook[i].pos.x, rook[i].pos.y);
			}
		}
	}
	return 0;
}