#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short coef[9];

void parse(char output[]){
	char len, i, start=8;
	char operator;
	char prefix[2];
	short tmp;

	while((start >= 0) && (coef[start] == 0) ){
		start--;
	}
	if(start < 0){
		strcpy(output, "0");
		return ;
	}
	
	tmp = abs(coef[start]);
	if(coef[start] < 0) {
		strcpy(prefix, "-");
	}
	else{
		strcpy(prefix, "");
	}

	if((tmp != 1) && (start >= 2)){
		len = sprintf(output, "%s%hdx^%hhd", prefix, tmp, start);
	}
	else if ((tmp != 1) && (start == 1)){
		len = sprintf(output, "%s%hdx", prefix, tmp);
	}
	else if ((tmp != 1) && (start == 0)){
		len = sprintf(output, "%s%hd", prefix, tmp);
	}		
	else if ((tmp == 1) && (start >= 2)){
		len = sprintf(output, "%sx^%hhd", prefix, start);
	}
	else if ((tmp == 1) && (start == 1)){
		len = sprintf(output, "%sx", prefix);
	}
	else if ((tmp == 1) && (start == 0)){
		len = sprintf(output, "%s1", prefix);
	}
	
	for(i = start - 1; i>=0; i--){
		if(coef[i] == 0) continue;
		
		operator = (coef[i] > 0)? '+' : '-';
		coef[i] = abs(coef[i]); 
		if((coef[i] > 1) && (i>=2)){
			len += sprintf(output + len, " %c %hdx^%hhd", operator, coef[i], i);
		}
		else if ((coef[i] > 1) && (i == 1)){
			len += sprintf(output + len, " %c %hdx", operator, coef[i]);
		}
		else if ((coef[i] > 1) && (i == 0)){
			len += sprintf(output + len, " %c %hd", operator, coef[i]);
		}		
		else if ((coef[i] == 1) && (i >= 2)){
			len += sprintf(output + len, " %c x^%hhd", operator, i);
		}
		else if ((coef[i] == 1) && (i == 1)){
			len += sprintf(output + len, " %c x", operator);
		}
		else if ((coef[i] == 1) && (i == 0)){
			len += sprintf(output + len, " %c 1", operator);
		}
	}
}

int main(){
	short i;
	char output[128];

	while(1 == scanf("%hd", &coef[8])){
		for(i=7; i>=0; i--){
			scanf("%hd", &coef[i]);
		}
		parse(output);
		
		printf("%s\n",output);
		
	}	
	
	return 0;
}