#include <stdio.h>
#include <string.h>
#define LEN 11
#define TRUE 1
#define FALSE 0

void setRange(char *target, char start, char end, char value){
	while(start <= end){
		target[start++] = value; 
	} 
}

int main(){
	char tok[2][6];
	char ans[LEN];
	char LEN_1 = LEN - 1;
	char num;
	FILE *fp = stdin;
	while(1 == fscanf(fp, "%hhd", &num)){
		if(0 == num) break;
		setRange(ans, 1, LEN_1, TRUE);
		fscanf(fp, "%s %s", tok[0], tok[1]);
		while(1){			
			if(!strcmp(tok[0], "too") && !strcmp(tok[1], "high")){
				setRange(ans, num, LEN_1, FALSE);
			} else if(!strcmp(tok[0], "too") && !strcmp(tok[1], "low")){
				setRange(ans, 1, num, FALSE);
			} else if (!strcmp(tok[0], "right") && !strcmp(tok[1], "on")){
				if(ans[num] == TRUE) puts("Stan may be honest");
				else puts("Stan is dishonest");
				break;
			}
			fscanf(fp, "%hhd", &num);
			fscanf(fp, "%s %s", tok[0], tok[1]);
		}
		
	}
	return 0;
}