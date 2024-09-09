#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11

int compareChar(const void *a, const void *b){
	return *(char *)a - *(char *)b;
}

int main(){
	int nTest, done;
	char clist[MAX], len;
	scanf("%d",&nTest);
	while(nTest >= 1){
			
		nTest--;
		scanf("%s",clist);
		len = strlen(clist); 
		qsort(clist, len, sizeof(char), compareChar);
		done = 0;
		while(!done){
			short j, ell, k;
			printf("%s\n",clist);
			j = len - 2;
			while ((clist[j] >= clist[j+1]) && (j >= 0)){
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
		printf("\n");
	}
	return 0;
}