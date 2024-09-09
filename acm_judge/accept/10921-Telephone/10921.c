#include <stdio.h>
#include <string.h>
#define PLEN 32

char hash[256];


int main(){
	short i;
	char phone[PLEN], *c;
	memset(hash, '*', 256);
	for(i=0; i<15; i++){
		hash['A' + i] = i/3 + '2';
	}
	for(i=0;i<4; i++){
		hash['P'+i] = '7';
	}
	for(i=0;i<3; i++){
		hash['T'+i] = '8';
	}
	for(i=0;i<4; i++){
		hash['W'+i] = '9';
	}
	hash['-'] = '-';
	hash['1'] = '1';
	hash['0'] = '0';
	while(1 == scanf("%s", phone)){
		c = phone;
		while(*c != '\0'){
			printf("%c", hash[*c]);
			c++;
		}
		printf("\n");
	}
	return 0;
}