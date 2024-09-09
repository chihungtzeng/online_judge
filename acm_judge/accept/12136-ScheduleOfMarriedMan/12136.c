#include <stdio.h>
#define CONVERT_TO_MINUTE(h, m) (h*60 + m)

enum{
	DANNY,
	MEETING
};

enum {
	START,
	END
};

struct Interval{
	int pin[2];
};

int isOverlap(struct Interval timeInterval[2]){
	if(timeInterval[DANNY].pin[START] > timeInterval[MEETING].pin[END]) return 0;
	if(timeInterval[DANNY].pin[END] < timeInterval[MEETING].pin[START]) return 0;
	return 1;
}

int main(){
	int nTest;
	int hh, mm;
	int i, j;
	int k=1;
	struct Interval timeInterval[2];
	scanf("%d", &nTest);
	
	while(nTest--){
		for(i=0; i<2; i++){
			for(j=0; j<2; j++){
				scanf("%d:%d", &hh, &mm);
				timeInterval[i].pin[j] = CONVERT_TO_MINUTE(hh, mm);
			}
		}
		if(isOverlap(timeInterval)){
			printf("Case %d: Mrs Meeting\n",k++);
		} else {
			printf("Case %d: Hits Meeting\n", k++);
		}
	}
	
	return 0;
}