/*AC 0.044s*/
#include <stdio.h>
#include <string.h>
#define LINELEN 100


int main(){
	int nTest;
	int startPage, endPage, nPage, sigSize, nSig, sheetPerSig, nPagePerSig;
	int nPageLastSig, nSheetLastSig;
	short first=1;
	short i,j, sheet, sig;
	char line[LINELEN];
	FILE *fp;
	
	fp = stdin;
	
	
	while(NULL != (fgets(line, LINELEN, fp)	)){
		nPage = atoi(strtok(line, "; "));
		sheetPerSig = atoi(strtok(NULL, "; "));
		if(first){
			first = 0;
		}
		else {
			printf("\n");
		}
		nPagePerSig = (sheetPerSig << 2);
		nSig = nPage / nPagePerSig;
		nPageLastSig = nPage - nSig*nPagePerSig;
		if(nPageLastSig > 0){
			nSig++;
		}
		nSheetLastSig = nPageLastSig / 4;
		if(nPageLastSig % 4 != 0){
			nSheetLastSig++;
		}
		

		for(sig = 1; sig <= nSig; sig++){
			startPage = (sig - 1)*nPagePerSig + 1;
			printf("signature %d\n",sig);
			endPage = startPage + nPagePerSig - 1;
			for(sheet = 1; sheet <= sheetPerSig; sheet++){
				printf(" sheet %d: pages %d and %d (front); pages %d and %d (back)\n",sheet, startPage+1, endPage -1, endPage, startPage);
				startPage += 2;
				endPage -=2;
			}
		}
		/*last signature: No need for dealing with the last signature */
		/*
		startPage = (nSig - 1)*nPagePerSig + 1;
		endPage = (nSig - 1)*nPagePerSig + (nSheetLastSig << 2);
		printf("signature %d\n",nSig);
		for(sheet = 1; sheet <= nSheetLastSig; sheet++){
				printf(" sheet %d: pages %d and %d (front); pages %d and %d (back)\n",sheet, startPage+1, endPage -1, endPage, startPage);
				startPage += 2;
				endPage -=2;
		}
		*/
	}
	
	return 0;
}
