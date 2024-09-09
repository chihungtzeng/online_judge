#include <stdio.h>
#include <stdlib.h>
#define MAX 128

int main(){
	char line[MAX];
	char ch, *check;
	short pos, n;
	
	while(2 == scanf("%hd %s", &n, line)){
		if((n == 0) && (line[0] == '0')){
			break;
		}
		ch = n + '0';
		pos = 0;
		check = line;
		while(*check != '\0'){
			if(*check != ch){
				line[pos++] = *check;
			}
			check++;
		}
		line[pos] = '\0';
		
		pos=0;
		while(line[pos] == '0'){
			pos++;
		}
		if(line[pos] == '\0'){
			printf("0\n");
		}
		else{
			printf("%s\n", line+pos);
		}
		
	}
	
	return 0;
}