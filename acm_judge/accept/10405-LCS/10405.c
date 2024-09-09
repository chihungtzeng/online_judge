#include <stdio.h>
#include <string.h>
#define LEN 1002
#define MAX(a, b) ((a) < (b)? (b) : (a))

int main(){
	char seq[2][LEN];
	short LCS[LEN][LEN];
	short i, j, seqLen[2];
	FILE *fp = stdin;

	for(i=0; i<LEN; i++){
		LCS[i][0] = 0;
		LCS[0][i] = 0;
	}	
	
	while(NULL != fgets(&seq[0][1], LEN, fp)){
		if(NULL == fgets(&seq[1][1], LEN, fp)){
			return 0;
		}
		for(i=0; i<2; i++){
			/* -1 is for '\n' character*/
			seqLen[i] = strlen(seq[i] + 1) - 1;
		}
		
		for(i=1; i<=seqLen[0]; i++){
			for(j=1; j<=seqLen[1]; j++){
				if(seq[0][i] == seq[1][j]){
					LCS[i][j] = LCS[i-1][j-1] + 1;
				} else {
					LCS[i][j] = MAX(LCS[i][j-1], LCS[i-1][j]);
				}
			}
		}
		printf("%hd\n", LCS[seqLen[0]][seqLen[1]]);
	}	
	
	return 0;
}