#include <stdio.h>

int isClapNum(int n){
	if(n % 7 == 0) return 1;
	while(n > 0){
		if (n % 10 == 7) return 1;
		n = n / 10;
	}
	return 0;
}

void solve(int nPeople, int personm, int clapk){
	int step[2], nStep, clapCount, curCounter = personm;
	int i, j;
	int done;	
	if((personm == nPeople) || (personm == 1)){
		nStep = 1;
		step[0] = (nPeople - 1) << 1;
	} else {
		nStep = 2;
		step[0] = (nPeople - personm ) << 1;
		step[1] = (personm - 1) << 1;
	}
	clapCount = isClapNum(personm)? 1 : 0;
	done = 0;
	while(clapCount < clapk){
		for(i=0; (i<nStep) && (clapCount < clapk); i++){
			curCounter += step[i];
			if(isClapNum(curCounter)){
				clapCount++;
			}
		}
	}
	printf("%d\n", curCounter);
}


int main(){
	int nPeople, personm, clapk;
	while(3 == scanf("%d %d %d", &nPeople, &personm, &clapk)){
		if(nPeople == 0) break;
		else solve(nPeople, personm, clapk);
	} 
	return 0;
}