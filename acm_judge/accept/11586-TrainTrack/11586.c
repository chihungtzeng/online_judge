#include <stdio.h>
#include <stdlib.h>
#define MAX 10000


int main(){
	short m, f;
	short nTest;
	char line[MAX];
	char *c;

	gets(line);
	nTest = atoi(line);
	
	while(nTest >= 1){
		nTest--;
		gets(line);
		c = line;
		m = 0;
		f = 0;
		while(*c != '\0'){
			if(*c == 'M'){
				m++;
			}
			else if (*c == 'F'){
				f++;
			}
			
			c++;
		}
		if((m == f) && (m > 1)){
			printf("LOOP\n");
		}
		else {
			printf("NO LOOP\n");
		}
	}	
	
	return 0;
}