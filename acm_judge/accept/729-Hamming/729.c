#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

int main(){
	short nTest;
	char clist[MAX], len, dist, done, nZero;
	char first = 1;
	char j, ell, k;
	scanf("%hd",&nTest);
	while(nTest >= 1){
			
		nTest--;
		scanf("%hhd %hhd", &len, &dist);
		nZero = len - dist;
		for(j= 0; j < nZero; j++){
			clist[j] = '0';
		}
		for(j=nZero; j<len; j++){
			clist[j] = '1';
		}
		clist[len] = '\0';
		
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		
		done = 0;
		while(!done){
			
			printf("%s\n", clist);
			
			j = len - 2;
			while ( (clist[j] >= clist[j+1]) && (j >= 0)){
				j--;
			}
			if (j < 0){
				done = 1;
				continue;
			}
			ell = len - 1;
			while(clist[j] >= clist[ell]){
				ell--;
			}
			clist[j] = clist[j] ^ clist[ell];
			clist[ell] = clist[j] ^ clist[ell];
			clist[j] = clist[j] ^ clist[ell];
			k = j+1;
			ell = len - 1;
			while(k < ell){
				clist[k] = clist[k] ^ clist[ell];
				clist[ell] = clist[k] ^ clist[ell];
				clist[k] = clist[k] ^ clist[ell];
				k++;
				ell--;
			}
		}
		/*printf("\n");*/
	}
	return 0;
}