#include <stdio.h>
#define YES 1
#define NO 0

short isPalindromTime(short HH, short MM){
	if(HH == 0){
		if(MM < 10) return YES;
		else if(MM % 10 == MM / 10) return YES;
		else return NO;
	}
	if((HH > 0) && (HH < 10)){
		if (MM % 10 == HH) return YES;
		else return NO;   
	}
	if((HH % 10 == MM / 10) && (HH / 10 == MM % 10)) return YES;
	else return NO;
}

void nextTime(short *HH, short *MM){
	if(*MM < 59){
		*MM = *MM + 1;
		return ;
	}
	else {
		*MM = 0;
		*HH = *HH + 1;
		if (*HH == 24) *HH = 0;
		return ;
	} 
}

int main(){
	short HH, MM;
	short nextHH, nextMM;
	short nTest;
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd:%hd",&HH, &MM);
		nextTime(&HH, &MM);
		while(isPalindromTime(HH, MM) == NO){
			nextTime(&HH, &MM);
		}
		printf("%02hd:%02hd\n", HH, MM);
	}
	return 0;
}