#include <stdio.h>

char chess[3][4];
char nO, nX;


char win(char target){
	char i, j, result;
	/*row*/
	for(i=0; i<3; i++){		
		result = 1;
		for(j=0; (j<3) && (result); j++){
			if(chess[i][j] != target) result = 0;
		}
		if(result) return 1;
	}
	/*column*/
	for(i=0; i<3; i++){		
		result = 1;
		for(j=0; (j<3) && (result); j++){
			if(chess[j][i] != target) result = 0;
		}
		if(result) return 1;
	}
	/*diagonal*/
	result = 1;
	for(i=0; i<3; i++){
		if(chess[i][i] != target) result = 0;
	}
	if(result) return 1;
	result = 1;
	for(i=0; i<3; i++){
		if(chess[2-i][i] != target) result = 0;
	}
	if(result) return 1;
	return 0;
}

int main(){
	short nTest;
	char i, j, xWin, oWin;
	scanf("%hd\n",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%s %s %s", chess[0], chess[1], chess[2]);
		nO = 0;
		nX = 0;
		for(i=0; i<3; i++){
			for(j=0; j<3; j++){
				if(chess[i][j] == 'X') nX++;
				if(chess[i][j] == 'O') nO++;
			}
		}
		xWin = win('X');
		oWin = win('O');
		/*printf("xWin=%hhd oWin=%hhd nX=%hhd nO=%hhd\n",xWin, oWin, nX, nO);*/
		if(xWin && oWin) puts("no");
		else if (xWin && (nX -1 == nO)) puts("yes");
		else if (oWin && (nX == nO)) puts("yes");
		else if ((!xWin && !oWin) && ((nX == nO) || (nX - 1 == nO))) puts("yes");
		else puts("no"); 
	}
	return 0;
}