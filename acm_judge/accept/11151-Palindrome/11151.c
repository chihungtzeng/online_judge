#include <stdio.h>
#include <string.h>
#define MAX 2000

void reverse(char *target, char *src, short len){
	short i;
	for(i= len - 1; i>=0; i--){
		target[i] = src[len - 1 - i];
	}
	target[len] = '\0';
} 

short max(short a, short b){
	if(a > b) return a;
	else return b;
}

int main(){
	char line[MAX], rline[MAX];
	short nTest;
	short len, i, j;
	short t[MAX][MAX];
	FILE *fp;
	char c;
	
	fp = stdin;
	
	fgets(line, MAX, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		/*
		len = 0;
		while(1){
			c = getchar();
			if((c == '\n') || (c == EOF)){
				break;
			}
			else{
				line[len++] = c;
			}
		}
		*/
		fgets(line, MAX, fp);
		len = strlen(line);
		if(len == 0){
			printf("0\n");
			continue;
		}
		if(line[len - 1] = '\n'){
			len--;
			line[len] = '\0';
		} 
		reverse(rline, line, len);
		memset(t, 0, sizeof(short)*MAX*MAX);
		for(i=0; i<len; i++){
			t[0][i] = (line[i] == rline[0])? 1 : 0;
			t[i][0] = (line[0] == rline[i])? 1 : 0;
		}
		for(i=1; i<len; i++){
			for(j=1; j<len; j++){
				if(rline[i] == line[j]){
					t[i][j] = t[i-1][j-1] + 1;
				}
				else{
					t[i][j] = max(t[i-1][j], t[i][j-1]);
				}
			}
		}
		printf("%hd\n",t[len-1][len-1]);
	}
	return 0;
}