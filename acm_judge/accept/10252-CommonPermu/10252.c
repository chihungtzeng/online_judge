#include <stdio.h>
#include <string.h>
#define MAX 1024

short min(short a, short b){
	if(a < b) return a;
	else return b;
}

int main(){
	char s[MAX], t[MAX], *ch, i;
	short sOccr[26], tOccr[26];
	short j, ell;
	
	while(NULL != fgets(s, MAX, stdin)){
		fgets(t, MAX, stdin);
		memset(sOccr, 0, sizeof(short)*26);
		memset(tOccr, 0, sizeof(short)*26);
		for(ch = s; *ch != '\n'; ch++) sOccr[*ch - 'a'] += 1;
		for(ch = t; *ch != '\n'; ch++) tOccr[*ch - 'a'] += 1;
		for(i=0; i<26;i++){
			/*printf("%hd(%hd) ",sOccr[i], tOccr[i]);*/
			
			ell = min(sOccr[i], tOccr[i]);
			for(j=0; j<ell; j++){
				printf("%c",i + 'a');
			}
			
		}
		printf("\n");
	}
	return 0;
}