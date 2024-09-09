#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
#define NOTRY 15
#define MAX 101
#define YES 1
#define NO 0
#define VERBOSE 0



int rTable[][3] ={ {1, 0, 2}, {0, 1, 1}, {2, 1, 0}};
short nX, nY, nZ;
short qs[MAX];
short qslen;
short qCount;
short s1,s2;

short quarkProduct(){
	short result=0;
	short i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(
				((s1 & (1 << i)))
				&& 
				((s2 & (1 << j)))
				){
				result |= (1 << rTable[i][j]);
			}
		}
	}
	return result;
}

int main(){
	short i, j;
	for(i=0; i<8; i++){
		for(j=0;j<8;j++){
			s1=i;
			s2=j;
			printf("ra[%d][%d]=%d;\n",i, j, quarkProduct());
		}
	}
	return 0;
}