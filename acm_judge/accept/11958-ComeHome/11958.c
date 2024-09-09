#include <stdio.h>
#include <string.h>
#define MAX 101

char nBus;
short busTime; /*In terms of minutes of the Day*/
short startTime;
short driveTime;
short ans;
char timefmt[8];

short timeFmtToMinute(char *tfmt){
	/*tfmt is HH:MM*/
	char *tok;
	short result;
	tok = strtok(tfmt, ":");
	result = atoi(tok)*60;
	tok = strtok(NULL, ":");
	result += atoi(tok);
	return result;
}

int main(){
	char nTest;
	char k = 1;
	short i;
	short tmp;
	scanf("%hhd", &nTest);
	while(nTest--){
		scanf("%hhd %s", &nBus, timefmt);
		startTime = timeFmtToMinute(timefmt);
		ans = 0x7fff;
		for(i=0; i<nBus; i++){
			scanf("%s %hd", timefmt, &driveTime);
			tmp = timeFmtToMinute(timefmt);
			if(tmp < startTime) tmp += 1440;
			tmp = tmp - startTime + driveTime; 
			if(tmp < ans) ans = tmp;
		}
		printf("Case %hhd: %hd\n", k++, ans);
	}
	
	return 0;
}