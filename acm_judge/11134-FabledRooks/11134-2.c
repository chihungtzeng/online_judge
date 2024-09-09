/*OK but TLE*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOK_NUM 5001
#define TRUE 1
#define FALSE 0
#define OCCUPY 1
#define VACUMN 0
#define DEBUG 0

struct Range {
	short left, right;
};

int solve(short nRook, struct Range *range, short *rookPos, short curRookIndex, char *seat){
	if(curRookIndex > nRook) return EXIT_SUCCESS;
		
	short i;
	int status;
	
	
	for(i=range[curRookIndex].left; i<=range[curRookIndex].right; i++){
		if(seat[i] == VACUMN){
			seat[i] = OCCUPY;
			rookPos[curRookIndex] = i;
			status = solve(nRook, range, rookPos, curRookIndex + 1, seat);
			if(status == EXIT_SUCCESS){
				#if DEBUG
				printf("find seat %hd for rook %hd\n", i, curRookIndex);
				#endif
				return EXIT_SUCCESS;
			} else {
				seat[i] = VACUMN;
			}
		}
	}
	/*no seat is availiabe*/
	#if DEBUG
	printf("no seat for rook %hd, with range [%hd %hd]\n", 
		curRookIndex, range[curRookIndex].left, range[curRookIndex].right);
	#endif
	return EXIT_FAILURE;
}

int main(){
	struct Range *xRange, *yRange;
	short *xPos, *yPos;
	char *seat;
	int status;
	short nRook, i;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;

	xRange = (struct Range *) malloc(sizeof(struct Range)*MAX_ROOK_NUM);
	yRange = (struct Range *) malloc(sizeof(struct Range)*MAX_ROOK_NUM);
	xPos = (short *) malloc(sizeof(short *)*MAX_ROOK_NUM);
	yPos = (short *) malloc(sizeof(short *)*MAX_ROOK_NUM);
	seat = (char *) malloc(sizeof(char)*MAX_ROOK_NUM);	
	
	while(1 == fscanf(fp, "%hd", &nRook)){
		if(nRook == 0) break;
		for(i=1; i<=nRook; i++){
			fscanf(fp, "%hd %hd %hd %hd", 
				&(xRange[i].left), &(yRange[i].left),
				&(xRange[i].right), &(yRange[i].right));
		}
		
		memset(seat, VACUMN, sizeof(seat[0])*(nRook + 1));
		status = solve(nRook, xRange, xPos, 1, seat);		
		if(status == EXIT_FAILURE){
			puts("IMPOSSIBLE");
			continue;
		}
		
		memset(seat, VACUMN, sizeof(seat[0])*(nRook + 1));
		status = solve(nRook, yRange, yPos, 1 , seat);
		if(status == EXIT_FAILURE){
			puts("IMPOSSIBLE");
			continue;
		}		 
		
		/*successfully find a solution*/	
		for(i=1; i<=nRook; i++){
				printf("%hd %hd\n", xPos[i], yPos[i]);
		}
	}
	free(xRange);
	free(yRange);
	free(xPos);
	free(yPos);
	free(seat);
	return 0;
}