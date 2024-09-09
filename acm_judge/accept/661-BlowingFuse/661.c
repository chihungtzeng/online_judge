#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32
#define ON 1
#define OFF 0

int main(){
	char power[MAX];
	int nDevice, nOp, deviceId;
	int powerConsumption[MAX];
	int curPower, maxPower;
	int threshold;
	int i;
	int caseId = 1;
	
	while(3 == scanf("%d %d %d", &nDevice, &nOp, &threshold)){
		if(nDevice == 0) break;
		
		memset(power, OFF, MAX);
		curPower = 0;
		maxPower = 0;
		for(i=1; i<=nDevice; i++){
			scanf("%d", &powerConsumption[i]);
		}
		for(i=0; i<nOp; i++){
			scanf("%d", &deviceId);
			if(power[deviceId] == OFF){
				curPower += powerConsumption[deviceId];
				power[deviceId] = ON;
				if(curPower > maxPower){
					maxPower = curPower;
				}
			}
			else {
				curPower -= powerConsumption[deviceId];
				power[deviceId] = OFF;
			}
		}
		printf("Sequence %d\n", caseId++);
		if(maxPower > threshold){
			printf("Fuse was blown.\n");
		}
		else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", maxPower);
		}
		
		printf("\n");
	}
	
	return 0;
}