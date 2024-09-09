#include <stdio.h>
#include <string.h>
#define MAX 101

char wolfPos[MAX][MAX];
unsigned int nPath[MAX][MAX];
short nWolf;
short w, h;

void findNPath(){
	short x, y;
	
	nPath[0][0] = 1;
	for(x=1; x <= w; x++){
		if(wolfPos[x][0] == 1) nPath[x][0] == 0;
		else nPath[x][0] = nPath[x-1][0];
	}
	for(y=1; y <= h; y++){
		if(wolfPos[0][y] == 1) nPath[0][y] == 0;
		else nPath[0][y] = nPath[0][y-1];
	}
	
	for(x = 1; x<=w; x++){
		for(y=1; y<=h; y++){
			if(wolfPos[x][y] == 1){
				nPath[x][y] = 0;
			}
			else{
				nPath[x][y] = nPath[x-1][y] + nPath[x][y-1]; 
			}
		}
	}
}


int main(){
	short i, x, y;
	
	
	while(2 == scanf("%hd %hd", &w, &h)){
		if((0 == w) && (0 == h)){ break;}
		memset(wolfPos, 0, sizeof(char)*MAX*MAX);
		memset(nPath, 0, sizeof(unsigned int)*MAX*MAX);
		scanf("%hd", &nWolf);
		for(i=0; i<nWolf; i++){
			scanf("%hd %hd", &x, &y);
			wolfPos[x][y] = 1;
		}
		findNPath();
		switch(nPath[w][h]){
			case 0: printf("There is no path.\n");
					break;
			case 1: printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
					break;
			default:
				printf("There are %u paths from Little Red Riding Hood's house to her grandmother's house.\n", nPath[w][h]);
					break;
		}
	}
	return 0;
}
