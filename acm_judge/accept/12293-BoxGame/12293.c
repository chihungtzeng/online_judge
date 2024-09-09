#include <stdio.h>

enum {
	ALICE,
	BOB
};


void solve(int n){
	int turn = ALICE;
	
	
	while((n > 1) && (n & 1)){
		turn = !turn;
		n = (n >> 1) + 1;
	}
	if(turn == BOB){
		puts("Bob");
	} else {
		puts("Alice");
	}
}

int main(){
	int n;
	while(1 == scanf("%d", &n)){
		if(n == 0) break;
		else solve(n);
	}
	return 0;
}