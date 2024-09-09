#include <stdio.h>
#include <stdlib.h>
#define LEN 512

int main(){
	char line[LEN], output[LEN];
	char first = 1;
	short nLine, nTest, kase=1, i, len;
	FILE *fp = stdin;
	char *cur;
	
	fgets(line, LEN, fp);
	nTest = atoi(line);
	while(nTest > 0){
		nTest--;
		if(first){
			first = 0;
		}
		else{
			puts("");
		}
		printf("Case %hd:\n", kase++);
		fgets(line, LEN, fp);
		nLine = atoi(line);
		for(i=nLine - 1; i>=0; --i){
			fgets(line, LEN, fp);
			cur = line;
			len = 0;
			while(*cur != '\n'){
				if((*cur != ' ') || (output[len - 1] != ' ')) output[len++] = *cur;
				cur++;
			}
			output[len] = '\0';
			puts(output);
		}
	}
	return 0;
}