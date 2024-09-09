#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 32

int toSecond(int hh, int mm, int ss){
	return hh*3600 + mm*60 + ss;
}

int main(){
	double odo = 0;
	double speed = 0;
	double elapseTime = 0;
	char line[LEN], *tok;
	int hh, mm, ss, curTime, preTime = 0;
	FILE *fp = stdin;
	while(NULL != fgets(line, LEN, stdin)){
		tok = strtok(line, " \n");
		
		sscanf(tok, "%d:%d:%d", &hh, &mm, &ss);
		curTime = toSecond(hh, mm, ss);
		
		tok = strtok(NULL, " \n");
		elapseTime = (curTime - preTime)/3600.0;
		odo += elapseTime * speed;
		preTime = curTime;
		if(tok == NULL){				
			printf("%02d:%02d:%02d %.2lf km\n",hh,mm,ss,odo);
		}
		else{
			speed = atof(tok);
		}
	}
	return 0;
}