#include <stdio.h>
#include <string.h>
#define LEN 256
#define DEBUG 0

int validDigit(char c){
	if(isalpha(c)) return 1;
	if(c == ' ') return 1;
	if(c == '!') return 1;
	if(c == ',') return 1;
	if(c == '.') return 1;
	if(c == ':') return 1;
	if(c == ';') return 1;
	if(c == '?') return 1;
	
	return 0;
}

void decode(char line[]){
	char code=0;
	int i, j, len;
	len = strlen(line) - 1;
	j = 0;
	i = len - 1;
	while(j < i){
		code = line[j];
		line[j] = line[i];
		line[i] = code;
		j++;
		i--;
	}
	
	for(i = 0; i < len; i++){
		code = line[i] - '0';
	
		while(!validDigit(code) && (i < len)){
			i++;
			code = (code << 3) + (code << 1) + line[i] - '0';
		}
		printf("%c", code);
	}
	printf("\n");
}

void encode(char line[]){
	char output[LEN], tmp;
	int len, i, j, pos;
	len = strlen(line);
	pos = 0;
	for(i=0; i<len; i++){
		if(validDigit(line[i])){
			pos += sprintf(output + pos, "%hhd", line[i]);
		}
	}
	j = 0;
	i = pos - 1;
	
	output[pos] = '\0';
	while(j < i){
		tmp = output[i];
		output[i] = output[j];
		output[j] = tmp;
		i--;
		j++;
	}
	puts(output);
	
}

int main(){
	char line[LEN];
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r"): stdin;
	while(NULL !=fgets(line, LEN, fp)){
		if(isdigit(line[0])){
			decode(line);
		} else {
			encode(line);
		}
	}

	return 0;
}
