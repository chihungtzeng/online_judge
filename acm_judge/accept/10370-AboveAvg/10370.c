#include <stdio.h>
#define MAX 1001

int main(){
	char grade[MAX];
	short nPeople, i, nAbove;
	short nTest;
	int sum;
	double avg;
	
	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%hd", &nPeople);
		sum = 0;
		for(i=0; i<nPeople; i++){
			scanf("%hhd", grade + i);
			sum += grade[i];
		}
		avg = (sum + 0.0)/nPeople;
		nAbove = 0;
		for(i=0; i<nPeople; i++){
			if(grade[i] > avg) nAbove++;
		}
		printf("%.3lf%%\n", (nAbove*100.0)/nPeople);
	}
	return 0;
}