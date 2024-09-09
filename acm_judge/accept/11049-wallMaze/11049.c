#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4
#define PERMIT 1
#define FORBIDDEN 0
#define MAX 7
#define DEBUG 0


char direction[MAX][MAX];
char isInQueue[MAX][MAX];
char dist[MAX][MAX];

char wall[3][4];
char start[2], end[2];


char min(char a, char b){
	if(a < b) return a;
	else return b;
}

char max(char a, char b){
	if(a < b) return b;
	else return a;
}

char walkable(char xfrom, char yfrom, char dir){
	char i;
	if(dir == WEST){
		for(i=0; i<3; i++){
			if((wall[i][0] == wall[i][2]) && (xfrom -1 == wall[i][0])){
				if((yfrom > wall[i][1]) && (yfrom <= wall[i][3])) return FORBIDDEN; 
			} 
		}
	}
	else if (dir == EAST){
		for(i=0; i<3; i++){
			if((wall[i][0] == wall[i][2]) && (xfrom == wall[i][0])){
				if((yfrom > wall[i][1]) && (yfrom <= wall[i][3])) return FORBIDDEN; 
			} 
		}
	}
	else if (dir == NORTH){
		for(i=0; i<3; i++){
			if((wall[i][1] == wall[i][3]) && (yfrom - 1 == wall[i][1])){
				if((xfrom > wall[i][0]) && (xfrom <= wall[i][2])) return FORBIDDEN; 
			} 
		}
	}
	else if (dir == SOUTH){
		for(i=0; i<3; i++){
			if((wall[i][1] == wall[i][3]) && (yfrom == wall[i][1])){
				if((xfrom > wall[i][0]) && (xfrom <= wall[i][2])) return FORBIDDEN; 
			} 
		}
	}
	else{
		printf("WRONG DIRECTION!\n");
		return FORBIDDEN;
	}
	return PERMIT;
}

void nextPosition(char xfrom, char yfrom, char *xto, char *yto, char dir){
	if(dir == NORTH){
		*xto = xfrom;
		*yto = yfrom - 1;
	}
	else if (dir == EAST){
		*xto = xfrom + 1;
		*yto = yfrom;
	}
	else if (dir == SOUTH){
		*xto = xfrom;
		*yto = yfrom + 1;
	}
	else if (dir == WEST){
		*xto = xfrom - 1;
		*yto = yfrom;
	}
	else{
		printf("wrong direction when calling nextPositiion()\n");
	}
}

void solve(){
	short queue[1024];
	short head, tail;
	short pos; /*pos = 8*x + y*/
	char xfrom, yfrom, xto, yto;
	char output[64];
	
	memset(isInQueue, 0, sizeof(char)*MAX*MAX);
	memset(direction, 0, sizeof(char)*MAX*MAX);
	memset(dist, 36, sizeof(char)*MAX*MAX);
	 
	xfrom = start[0];
	yfrom = start[1];
	dist[xfrom][yfrom] = 0;
	pos = (xfrom << 3) + yfrom;
	queue[0] = pos;
	head = 0;
	tail = 1;
	isInQueue[xfrom][yfrom] = 1;	
	
	while(head < tail){
		char dir;
		pos = queue[head++];
		xfrom = pos >> 3;
		yfrom = pos & 7;
		for(dir=1; dir<=4; dir++){
			if(walkable(xfrom, yfrom, dir) == FORBIDDEN){
				continue;
			}
			nextPosition(xfrom, yfrom, &xto, &yto, dir);
			if((xto <= 0) || (xto >= 7) || (yto >= 7) || (yto <= 0)){
				continue;
			} 
			
			if(dist[xfrom][yfrom] + 1 < dist[xto][yto]){
				dist[xto][yto] = dist[xfrom][yfrom] + 1;
				direction[xto][yto] = dir;
				if(isInQueue[xto][yto] == 0){
					queue[tail++] = (xto << 3) + yto;
				}
			}
		}
		isInQueue[xfrom][yfrom] = 0;
	}
	if(DEBUG){
		char i, j;
		for(i=1; i<=6; i++){
			for(j=1; j<=6; j++){
				printf("%hhd ",dist[j][i]);
			}
			printf("\n");
		}
	}
	/*back trace from end point to start point*/
	xfrom = end[0];
	yfrom = end[1];
	pos = 0;
	while(direction[xfrom][yfrom] != 0){
		if(direction[xfrom][yfrom] == NORTH){
			output[pos++]  = 'N';
			nextPosition(xfrom, yfrom, &xto, &yto, SOUTH);	
		}
		else if(direction[xfrom][yfrom] == EAST){
			output[pos++]  = 'E';
			nextPosition(xfrom, yfrom, &xto, &yto, WEST);	
		}
		else if(direction[xfrom][yfrom] == SOUTH){
			output[pos++]  = 'S';
			nextPosition(xfrom, yfrom, &xto, &yto, NORTH);	
		}
		else if(direction[xfrom][yfrom] == WEST){
			output[pos++]  = 'W';
			nextPosition(xfrom, yfrom, &xto, &yto, EAST);	
		}
		else{
			printf("wrong direction is back trace\n");
			exit(0);
		}
		direction[xfrom][yfrom] = 0;
		xfrom = xto;
		yfrom = yto;
	}
	pos--; 
	while(pos >= 0){
		printf("%c", output[pos]);
		pos--;
	}
	printf("\n");
}


int main(){
	char i,j, tmpm, tmpM;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	while(2 == fscanf(fp, "%hhd %hhd", start, start + 1)){
		if((start[0] == 0) && (start[1] == 0)) break;
		
		fscanf(fp, "%hhd %hhd", end, end + 1);
		for(i=0; i<3; i++){
			fscanf(fp, "%hhd %hhd %hhd %hhd", wall[i], wall[i]+1, wall[i]+2, wall[i]+3);
			tmpm = min(wall[i][0], wall[i][2]);
			tmpM = max(wall[i][0], wall[i][2]);
			wall[i][0] = tmpm;
			wall[i][2] = tmpM;
			tmpm = min(wall[i][1], wall[i][3]);
			tmpM = max(wall[i][1], wall[i][3]);
			wall[i][1] = tmpm;
			wall[i][3] = tmpM;
		}
		if(DEBUG){
			printf("start: (%hhd %hhd) end: (%hhd %hhd)\n",start[0], start[1], end[0], end[1]);
			for(i=0; i<3; i++){
				printf("wall: (%hhd %hhd) to (%hhd %hhd)\n", wall[i][0], wall[i][1],wall[i][2],wall[i][3]);
			}
		}
		solve();
	}
	return 0;
}