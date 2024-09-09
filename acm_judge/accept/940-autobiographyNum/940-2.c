#include <stdio.h>
#include <string.h>
#define MAX 102
#define NUM 101

short aNum[128][MAX];	
void initANum(){
	short i;
	
	memset(aNum, 0, MAX << 7);
	/*The first three numbers are special*/
	aNum[0][0] = 4;
	aNum[0][1] = 1; 
	aNum[0][2] = 2;
	aNum[0][3] = 1;
	aNum[0][4] = 0;
	
	aNum[1][0] = 4;
	aNum[1][1] = 2; 
	aNum[1][2] = 0;
	aNum[1][3] = 2;
	aNum[1][4] = 0;

	aNum[2][0] = 5;
	aNum[2][1] = 2; 
	aNum[2][2] = 1;
	aNum[2][3] = 2;
	aNum[2][4] = 0;
	aNum[2][5] = 0;
	
	for(i=3; i<=100; i++){
		aNum[i][0] = i+4;
		aNum[i][1] = i;
		aNum[i][2] = 2;
		aNum[i][3] = 1;
		aNum[i][i+1] = 1;
	}
}

int main(){
	short nTest;
	char alphabet[MAX];
	short first=1, len, i, j;	
	
	initANum();
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		if(!first){
			printf("\n");
		}
		else{
			first = 0;
		}
		scanf("%s", alphabet);		
		len = strlen(alphabet);
		for(i=0; (i< NUM) && (aNum[i][0] <= len); i++){
			for(j=1; j<= aNum[i][0]; j++){
				printf("%c",alphabet[aNum[i][j]]);
			}
			printf("\n");
		}
	}	
	return 0;
}
