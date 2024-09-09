#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1

void printChar(char c){
	if(DEBUG){
		if(isprint(c)){
			printf("%c", c);
		}
		else{
			printf("[%hhu]",c);
		}
	}
	else{
		printf("%c", c);
	}
}

int main(){
	unsigned char *inChar, *occr, *output;
	int capacity=128, pos, i, j, nChar, count, controlPos;
	char c;
	FILE *fp;
	fp = (DEBUG)? fopen("3.in","r") : stdin;
	
	inChar = (unsigned char *) malloc(sizeof(unsigned char)*capacity);
	
	pos = 0;

	while( c = fgetc(fp)){
		if( (c == EOF)){
			break;
		}
		else{
			inChar[pos++] = c;
			if(pos == capacity){
				capacity = capacity << 1;
				inChar = (unsigned char *) realloc(inChar, sizeof(unsigned char)*capacity);
			}
		}
	}
	occr = (unsigned char *) malloc(sizeof(unsigned char)*capacity);
	nChar = pos;
	i = pos - 1;
	occr[i] = 1;
	while(i > 0){
		i--;
		if((inChar[i] == inChar[i+1]) && (occr[i+1] < 128)){
			occr[i] = occr[i+1] + 1;
		}
		else{
			occr[i] = 1;
		}
	}
	if(DEBUG){
		for(i=0; i<pos; i++){
			printf("%c(%hhd) ", inChar[i], occr[i]);
		}
		printf("\n");
	}
	
	output = (char *) malloc(sizeof(char)*capacity);
	count = 0;
	
	pos = (occr[0] > 2)? 0 : 1;
	
	controlPos = 0;
	output[0] = 0;
	for(i=0; i<	nChar; i++){
		if(occr[i] <= 2){
			output[controlPos] += 1;
			output[pos++] = inChar[i];
		}
		else if(occr[i] > 2){
			while(occr[i] > 128){
				controlPos = pos;
				output[controlPos] = 255;
				occr[i] -= 128;
				pos++;
				output[pos++] = inChar[i]; 
			}
			
			if(occr[i] > 2){
				controlPos = pos;
				output[controlPos] = 127 + occr[i];
				occr[i] = 0;
				pos++;
				output[pos++] = inChar[i];
				controlPos = pos;
				pos++; 
			}
			else{
				controlPos = pos;
				output[controlPos] = occr[i];
				pos++;
				for(j=0; j<occr[i]; j++){
					output[pos++] = inChar[i];
				}
			}
			while(occr[i] != 1){
					i++;
				}
			i++;
		}
		
		if((i<nChar) && (output[controlPos] == 127)){
			controlPos = pos;
			pos++;
			output[controlPos] = 0;
		}
	}
	if(DEBUG){
		printf("\ncontrolPos:%d pos:%d\n",controlPos, pos);
	}
	
	if(controlPos + 1 == pos){
		pos--;
	}
	for(i=0; i<pos; i++){
		printChar(output[i]);
	}
	if(DEBUG){
		printf("\n");
	}
	free(output);
	return 0;
}
