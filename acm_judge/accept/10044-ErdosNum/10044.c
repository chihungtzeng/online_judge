#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINELEN 2048


struct Vertex{
	
}

int main(){
	short nTest, nQuery, nRef, i, k=1;
	char line[LINELEN];
	char *tok;
	FILE *fp = stdin;
	fgets(line, LINELEN, fp);
	nTest = atoi(line);
	while(k<=nTest){
		fgets(line, LINELEN, fp);
		sscanf(line, "%hd %hd", &nRef, &nQuery);
		for(i=0; i<nRef; i++){
			fgets(line, LINELEN, fp);
			printf("%s\n",line);
		}
		for(i=0; i<nQuery; i++){
			fgets(line, LINELEN, fp);
			printf("%s\n",line);
		}
		k++;
	}
	
	
	return 0;
}