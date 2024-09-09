#include <stdio.h>
#include <string.h>
#define DEBUG 1
#define LEN 1002 
#define MAX(a, b) ((a) < (b)? (b) : (a))

int solve(char output[], char line[], int lineLen, int palindromLen){
	short i, j;
	char c;
	
}



int main(){
	char line[LEN];
	char output[LEN];
	FILE *fp;
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	while(1 == fscanf(fp, "%s", line + 1)){
		solve(output, line, strlen(line), 0);
	}
	return 0;
}