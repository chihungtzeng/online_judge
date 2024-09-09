#include <stdio.h>
#include <string.h>
#define LEN 32
#define MAX 128
#define DEBUG 0
#define LEFT 1
#define UP 2
#define UPLEFT 3

char statement[2][MAX][LEN];
char sLen, tLen;

void solve(){
	char src[MAX][MAX];
	short i, j, iPos, jPos, iPre, jPre, iCur, jCur, pre;
	char dp[MAX][MAX];
	char *output[MAX];
	int state;
	memset(src, 0xff, sizeof(char)*MAX*MAX);
	memset(dp, 0, sizeof(char)*MAX*MAX);
	
	for(i=0; i<sLen; i++){
		for(j=0; j<tLen; j++){
			state = strcmp(statement[0][i], statement[1][j]);
			iPos = i + 1;
			jPos = j + 1; 
			if(state == 0){
				dp[iPos][jPos] = dp[i][j] + 1;
				src[iPos][jPos] = UPLEFT;
			}
			else {
				if(dp[i][jPos] > dp[iPos][j]){
					src[iPos][jPos] = UP;
					dp[iPos][jPos] = dp[i][jPos];
				}
				else{
					src[iPos][jPos] = LEFT;
					dp[iPos][jPos] = dp[iPos][j];
				}
			}
		}
	}
	i = 0;
	iCur = sLen;
	jCur = tLen;
	
	while( (iCur > 0) && (jCur > 0)){
		if(src[iCur][jCur] == LEFT){
			jCur--;
			/*output[i++] = statement[1][jCur];*/
		}
		else if (src[iCur][jCur] == UP){
			iCur--;
			/*output[i++] = statement[0][iCur];*/
		}
		else{
			iCur--;
			jCur--;
			output[i++] = statement[0][iCur];
		}
	}
	if(i > 0){
		printf("%s", output[i-1]);
	}
	for(j=i-2; j>=0; j--){
		printf(" %s", output[j]);
	}
	printf("\n");
}

int main(){
	char i=0, j = 0;
	char done = 0;
	FILE *fp;
	fp = (DEBUG)? fopen("in2.txt","r") : stdin;

		while(1 == fscanf(fp, "%s", statement[i][j])){
			if(statement[i][j][0] == '#'){
				if(i == 0){
					sLen = j;
				}
				else{
					tLen = j;
				}		
				i++;
				j=0;
				if(i== 2){
					solve();
					i=0;
					j=0;
				}
			}
			else{
				j++;
			}
		}
		
	
	
	
	return 0;
} 