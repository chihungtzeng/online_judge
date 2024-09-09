#include <stdio.h>

int main(){
	short nE, nP, nNew, total, rRate, nBottle;
	short nTest;
	
	scanf("%hd", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd %hd %hd",&nP, &nE, &rRate);
		total = nP + nE;
		nBottle = 0;
		while(total >= rRate){
			nNew = total / rRate;
			total = (total % rRate) + nNew;
			nBottle += nNew;
		}
		printf("%hd\n",nBottle);
	}
	
	return 0;
}