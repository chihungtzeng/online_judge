#include <stdio.h>
#define MAX 20000
#define PUNCH 1
#define SPACE 0
#define LEN 15

int main(){
	char line[LEN];
	char message[MAX];
	short msgLen = 0;
	char c;
	short i;
	fgets(line, LEN, stdin);
	while(1){
		fgets(line, LEN, stdin);
		if(!strncmp(line, "___________", 11)){
			break;
		}
		c = 0;
		for(i=2; i <= 5 ;i++){
			if(line[i] == 'o'){
				c += 1 << (8 - i); 
			}
		}
		for(i = 7; i<= 9; i++){
			if(line[i] == 'o'){
				c+= 1 << (9 - i);
			}
		}
		message[msgLen++] = c;
	}
	message[msgLen] = '\0';
	printf("%s",message);
	return 0;
}


