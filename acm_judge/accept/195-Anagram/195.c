#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int compareChar(const void *a, const void *b){
	char x , y, c, d;
	x = *(char *)a;
	y = *(char *)b;
	c = tolower(x);
	d = tolower(y);
	if(c != d) return c - d;
	
	
	if(x == y) return 0;
	else if (isupper(x) && islower(y)) return -1; /*x is upper case, y is lower case*/
	else return 1;
	
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
		/*printf("sorted string:%s\n",clist);*/
		done = 0;
		while(!done){
			short j, ell, k;
			printf("%s\n",clist);
			j = len - 2;
			while ((compareChar(&clist[j], &clist[j+1]) >= 0) && (j >= 0)){
				j--;
			}
			if (j < 0){
				done = 1;
				continue;
			}
			ell = len - 1;
			while(compareChar(&clist[j], &clist[ell]) >= 0){
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