#include <stdio.h>
#include <string.h>
#define MAX 101
#define HHMM_TO_MINUTE(h, m) (((h) << 6) - ((h) << 2) + m)

char nBus;
short MM, HH;
short busTime; /*In terms of minutes of the Day*/
short startTime;
short driveTime;
short ans;
char timefmt[8];



int main(){
	char nTest;
	char k = 1;
	short i;
	short tmp;
	scanf("%hhd", &nTest);
	while(nTest--){
		scanf("%hhd %hd:%hd", &nBus, &HH, &MM);
		startTime = HHMM_TO_MINUTE(HH, MM);
		ans = 0x7fff;
		for(i=0; i<nBus; i++){
			scanf("%hd:%hd %hd", &HH, &MM, &driveTime);
			tmp = HHMM_TO_MINUTE(HH, MM);
			if(tmp < startTime) tmp += 1440;
			tmp = tmp - startTime + driveTime; 
			if(tmp < ans) ans = tmp;
		}
		printf("Case %hhd: %hd\n", k++, ans);
	}
	
	return 0;
}