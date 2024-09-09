#include <stdio.h>
#include <string.h>
#define STOP 8

struct VisitOrder{
	char node[10];
	char visited[6][6];
	char nVisited;
};

const char house[6][6] = {
/*0  1  2  3  4  5*/
{ 0, 0, 0, 0, 0, 0},
{ 0, 0, 1, 1, 0, 1},
{ 0, 1, 0, 1, 0, 1},
{ 0, 1, 1, 0, 1, 1}, /*row 3*/
{ 0, 0, 0, 1, 0, 1},
{ 0, 1, 1, 1, 1, 0},
};

 



void traverse(struct VisitOrder vo){
	struct VisitOrder backup;
	char i, lastpos, nextpos;
	
	if(vo.nVisited == STOP){		
		for(i=0; i<=STOP; i++){
			printf("%hhd", vo.node[i]);
		}
		printf("\n");
		return ;
	}
	memcpy(&backup, &vo, sizeof(vo));
	lastpos = vo.node[vo.nVisited];
	for(nextpos = 1; nextpos <= 5; nextpos++){
		if( (house[lastpos][nextpos] == 1) && (vo.visited[lastpos][nextpos] == 0)){
			vo.visited[lastpos][nextpos] = 1;
			vo.visited[nextpos][lastpos] = 1;
			vo.nVisited++;
			vo.node[vo.nVisited] = nextpos;
			traverse(vo);
			memcpy(&vo, &backup, sizeof(vo));
		}
	}
}

int main(){
	struct VisitOrder vo; 
	memset(&vo, 0, sizeof(vo));
	vo.node[0] = 1;
	traverse(vo);
	
	return 0;
}