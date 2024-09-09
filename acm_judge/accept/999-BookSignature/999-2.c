#include <stdio.h>
#include <stdlib.h>
#define LINELEN 100
#define BUFSIZE (1 << 20)


int main(){
	int startPage, endPage, nPage, nSig, sheetPerSig, nPagePerSig;
	int nPageLastSig, nSheetLastSig;
	int tmp;
	short first=1;
	short sheet, sig;
	char line[LINELEN];
	char *buf;
	size_t len, lentmp;
	FILE *fp;
	
	fp = stdin;
	buf = (char *) malloc(BUFSIZE);
	setbuf(stdout, buf);
	
	/*while(NULL != (fgets(line, LINELEN, fp)	)){*/
	while(2 == scanf("%d;%d",&nPage, &sheetPerSig)){
		
		/*
		nPage = atoi(strtok(line, "; "));
		sheetPerSig = atoi(strtok(NULL, "; "));
		*/
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
		nSheetLastSig = nPageLastSig >> 2;
		if(nPageLastSig & 3 != 0){
			nSheetLastSig++;
		}
		
		tmp = 0;
		for(sig = 1; sig <= nSig; sig++){
			startPage = tmp + 1;
			printf("signature %d\n",sig);
			endPage = startPage + nPagePerSig - 1;
			tmp = endPage;
			for(sheet = 1; sheet <= sheetPerSig; sheet++){
				printf(" sheet %d: pages %d and %d (front); pages %d and %d (back)\n",sheet, startPage+1, endPage -1, endPage, startPage);
				startPage += 2;
				endPage -=2;
			}
		}
		
	}
	fflush(stdout);
	free(buf);

	return 0;
}
