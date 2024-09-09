#include <stdio.h>

short findAns(short n, short m){
	short remain, nCompetition;
	short nextRound, ans;
	
	if(n == m) return 1;
	if(n < m) return -1;	
	
	
	nCompetition = n / m;
	remain = n % m;	
	if(nCompetition + remain < m) return -1;
	else {
		ans = findAns(nCompetition + remain, m);
		if(ans == -1){
			return -1;
		}
		else {
			return ans + nCompetition;
		}
	}
}

int main(){
	short n, m, nTest;
	short ans;
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd %hd", &n ,&m);
		ans = findAns(n, m);
		if(ans < 0){
			printf("cannot do this\n");
		}
		else{
			printf("%hd\n",ans);
		}
	}
	return 0;
}