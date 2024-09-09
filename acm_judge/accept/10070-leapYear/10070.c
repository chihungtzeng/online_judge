#include <stdio.h>
#include <string.h>
#define MAX 10000


int bigMod(char *s, int slen, int divisor){
	int i;
	int remainder=0;
	for(i = 0 ; i<slen; i++){
		remainder = ((10 * remainder) + s[i] - '0') % divisor; 
	}
	return remainder;
}

int main(){
	char line[MAX];
	FILE *fp;
	int year;
	char leap, huluculu, bulukulu, first;
	int len;

	fp = stdin;
	first = 1;
	while(NULL != fgets(line, MAX, fp)){
		len = strlen(line);
		line[len - 1] = '\0';
		len--;
		
		if(first){
			first = 0;
		}
		else {
			printf("\n");
		}
		if (bigMod(line, len, 4) != 0){
			leap = 0;
		}
		else{
			if((bigMod(line, len, 100) == 0) && (bigMod(line, len, 400) == 0)){
				leap = 1;
			}
			else if ((bigMod(line, len, 100) == 0) && (bigMod(line, len, 400) != 0)){
				leap = 0;
			}
			else {
				leap = 1;
			}
		}
		
		if(bigMod(line, len, 15) == 0){
			huluculu = 1;
		}
		else{
			huluculu = 0;
		}
		
		if (leap && (bigMod(line, len, 55) == 0)){
			bulukulu = 1;
		}
		else {
			bulukulu = 0;
		}
		
		if( (!leap) && (!huluculu) && (!bulukulu)){
			printf("This is an ordinary year.\n");
		}
		else{
			if(leap){
				printf("This is leap year.\n");
			}
			if(huluculu){
				printf("This is huluculu festival year.\n");
			}
			if(bulukulu){
				printf("This is bulukulu festival year.\n");
			}
		}
	}
	return 0;
}