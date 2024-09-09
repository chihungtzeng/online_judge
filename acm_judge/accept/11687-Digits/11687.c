#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 1000010

int findAns(int nDigit){
	int ans;
	
	if (nDigit == 1) ans = 1;	
	else ans = 1 + findAns(log10(nDigit) + 1);
	/*printf("nDigit=%d, ans=%d\n",nDigit,ans);*/
	return ans;
}

int main(){
	char *line;
	char *ch;
	int nDigit, ans;
	line = (char *) malloc(sizeof(char)*MAX);
	while(1){
		fgets(line, MAX, stdin);
		ch = line;
		nDigit = 0;
		if(!strncmp(line, "END", 3)){
			break;
		}
		while(isdigit(*ch)){
			nDigit += 1;
			ch++;
		} 
		if((nDigit == 1) && (line[0] == '0')){
			ans = 2;
		}
		else if ((nDigit == 1) && (line[0] == '1')){
			ans = 1;
		}
		else {
			ans = 1 + findAns(nDigit);
		}
		/*printf("nDigit=%d\n",nDigit);*/
		printf("%d\n",ans);
	}
	
	free(line);
	return 0;
}
