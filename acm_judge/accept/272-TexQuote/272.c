#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INSIDE 0
#define OUTSIDE 1

int main(int argc, char *argv[]){
	int state;
	char c;
	
	state = OUTSIDE;
	while ( EOF != (c=getchar())){
		if (c == '\"'){
			if (OUTSIDE == state){
				printf("``");				
			}
			else {
				printf("\'\'");
			} 
			state = 1 - state;
		}
		else {
			printf("%c",c);
		}
	}
	exit(0);
}