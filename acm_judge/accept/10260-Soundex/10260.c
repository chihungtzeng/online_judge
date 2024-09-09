#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 256

char map[LEN];


void buildMap(){
	map['A'] = 0;
	map['B'] = '1';
	map['C'] = '2';
	map['D'] = '3';
	map['E'] = 0;
	map['F'] = '1';
	map['G'] = '2';
	map['H'] = 0;
	map['I'] = 0;
	map['J'] = '2';
	map['K'] = '2';
	map['L'] = '4';
	map['M'] = '5';
	map['N'] = '5';
	map['O'] = 0;
	map['P'] = '1';
	map['Q'] = '2';
	map['R'] = '6';
	map['S'] = '2';
	map['T'] = '3';
	map['U'] = 0;
	map['V'] = '1';
	map['W'] = 0;
	map['X'] = '2';
	map['Y'] = 0;
	map['Z'] = '2';
}

void solve(char line[]){
	char *ptr, *outPos, pre;
	char output[LEN];
	ptr = line;
	outPos = output;
	*outPos = '\0'; 
	pre = 0;
	
	while(*ptr != '\0'){
		if((map[*ptr] != 0) && (map[*ptr] != pre)){
			*outPos = map[*ptr];			
			outPos++;
		} 
		pre = map[*ptr];
		ptr++;
	}
	if(*outPos != '\0'){
		*outPos = '\0';
	}
	puts(output);
}

int main(){
	buildMap();
	char line[LEN];
	while(1 == scanf("%s", line)){
		solve(line);
	}
	return 0;
}