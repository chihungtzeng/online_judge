#include <stdio.h>
#define LEN 1024

int main(){
	char line[LEN];
	FILE *fp = stdin;
	while(NULL != fgets(line, LEN, stdin)){
		printf("%s", line);
	}
	return 0;
}