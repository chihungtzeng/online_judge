#include <stdio.h>
#include <stdlib.h>
#define MAX 15

void removeIJK(char result[], char ability[], char nPeople, char i, char j, char k){
	char n, m;
	for(n=0, m = 0; n<nPeople; n++){
		if(!((n == i) || (n == j) || (n == k))){
			result[m++] = ability[n];
		}
	}
}

char solve(char nPeople, char ability[]){
	char i, j, k;
	char best = -1, tmp;
	char abilityAfterRemoved[MAX];
	if(nPeople < 3) return 0;
	for(i=nPeople -1; i>=2; --i){
		for(j=i-1; j >= 1; --j){
			for(k=j-1; k>=0; --k){
				removeIJK(abilityAfterRemoved, ability, nPeople, i, j, k);
				tmp = solve(nPeople - 3, abilityAfterRemoved);
				if (ability[i] + ability[j] + ability[k] >= 20){
					++tmp;
				}
				if(tmp > best) best = tmp;
			}
		}
	}
	return best;
}

int main(){
	char ability[MAX];
	char nPeople, i, k = 1;
	char nTeam;
	while(1 == scanf("%hhd", &nPeople)){
		if(0 == nPeople) return 0;
		for(i=0; i<nPeople; i++){
			scanf("%hhd", ability + i);
		}
		nTeam = solve(nPeople, ability);
		printf("Case %hhd: %hhd\n", k++, nTeam);
	}
	return 0;
}