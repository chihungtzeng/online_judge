/*AC*/
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
short ra[8][8];
short nX, nY, nZ;
short qs[MAX];
short qslen;
short qCount;
short s1,s2;

void initReaction();




short react(){
	/*
	DP: 
	row represents length, column represents the start point of the input seq
	pResult[i, j] maintains the possible quark generted.
	0 <= i <= qslen - 1, 1 <= j <= qslen 
	*/
	short pResult[qslen + 1][qslen];
	short i,j, k, len, ilen, stopPoint;
	
	memset(pResult, 0, sizeof(short)*(qslen + 1)*qslen);
	
	/*row 1*/
	for(i = qslen - 1; i>=0;i--){
		pResult[1][i] = 1 << qs[i];
	}
	/*row 2.. row n*/
	for(len = 2; len <= qslen; len++){
		short irange;
		irange = qslen - len;
		for(i=irange; i >=0 ; i--){
			short ableStop;
			
			ilen = 1;
			ableStop = 0;
			while((ilen < len) && (!ableStop)){
				
				pResult[len][i] |= ra[pResult[ilen][i]][pResult[len - ilen][i + ilen]];
				
				if(pResult[len][i] == 7){
					ableStop = 1;
				}
	
				ilen++;
	
			}
		}
	}
	
#if VERBOSE
		for(len = 1; len<=qslen; len++){
			short irange;
			irange = qslen - len;
			for(i=0; i<=irange; i++){
				printf("%hd ", pResult[len][i]);
			}
			printf("\n");
		}
#endif

	
	return pResult[qslen][0];
}



int main(){
	int nTest,i;
	char seqStr[MAX];
	FILE *fp;


#if DEBUG
	fp = fopen("in.txt","r");
#else
	fp = stdin;
#endif

	
	fscanf(fp, "%d", &nTest);
	initReaction();	
	while(nTest >= 1){
		nTest--;
		fscanf(fp, "%s",seqStr);

#if DEBUG
		printf("before: string: %s: len::%ld\n",seqStr, strlen(seqStr));
#endif		
		
		qslen = strlen(seqStr);
		
		
		nZ =0;
		for(i = qslen - 1; i >= 0;i--){
			
			qs[i] = seqStr[i] - 'X';
		}
		
#if DEBUG
			printf("nX:%d nY:%d nZ:%d\n",nX,nY,nZ);
#endif

		qCount = react(qs);
		
		
		int idx;
		if((qCount & 4)){
			idx = 2;
		} 
		else if (qCount & 2){
			idx = 1;
		}
		else {
			idx = 0;
		}
#if DEBUG
			printf("qCount: %hd\n",qCount);
#endif
		printf("%c\n",idx+'X');		

	}
	return 0;
}
void initReaction(){
ra[0][0]=0;
ra[0][1]=0;
ra[0][2]=0;
ra[0][3]=0;
ra[0][4]=0;
ra[0][5]=0;
ra[0][6]=0;
ra[0][7]=0;
ra[1][0]=0;
ra[1][1]=2;
ra[1][2]=1;
ra[1][3]=3;
ra[1][4]=4;
ra[1][5]=6;
ra[1][6]=5;
ra[1][7]=7;
ra[2][0]=0;
ra[2][1]=1;
ra[2][2]=2;
ra[2][3]=3;
ra[2][4]=2;
ra[2][5]=3;
ra[2][6]=2;
ra[2][7]=3;
ra[3][0]=0;
ra[3][1]=3;
ra[3][2]=3;
ra[3][3]=3;
ra[3][4]=6;
ra[3][5]=7;
ra[3][6]=7;
ra[3][7]=7;
ra[4][0]=0;
ra[4][1]=4;
ra[4][2]=2;
ra[4][3]=6;
ra[4][4]=1;
ra[4][5]=5;
ra[4][6]=3;
ra[4][7]=7;
ra[5][0]=0;
ra[5][1]=6;
ra[5][2]=3;
ra[5][3]=7;
ra[5][4]=5;
ra[5][5]=7;
ra[5][6]=7;
ra[5][7]=7;
ra[6][0]=0;
ra[6][1]=5;
ra[6][2]=2;
ra[6][3]=7;
ra[6][4]=3;
ra[6][5]=7;
ra[6][6]=3;
ra[6][7]=7;
ra[7][0]=0;
ra[7][1]=7;
ra[7][2]=3;
ra[7][3]=7;
ra[7][4]=7;
ra[7][5]=7;
ra[7][6]=7;
ra[7][7]=7;
}