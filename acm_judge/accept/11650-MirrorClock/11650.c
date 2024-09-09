#include <stdio.h>
#include <string.h>
#define LEN 100

int main(){
	int mH, mM, H, M;
	int nTest;
	int hAngle, mAngle, offset;
	char line[LEN];
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%s", line);
		mH = atoi(strtok(line, ":"));
		mM = atoi(strtok(NULL, ":"));
		mAngle = mM*180; 
		hAngle = (mH % 12)*900 + (mM*15);
		/*printf("mAngel=%d hAngel=%d\n",mAngle, hAngle);*/		
		
		mAngle = 10800 - mAngle;
		hAngle = 10800 - hAngle;
		
		H = hAngle / 900;
		M = mAngle / 180;
		if(M == 60) M = 0;
		if(H == 0) H = 12;
		
		printf("%02d:%02d\n",H,M);
	}
}