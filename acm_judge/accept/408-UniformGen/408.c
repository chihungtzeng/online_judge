#include <stdio.h>

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b,a % b);
}

int main(){
	int n, m;
	while(2 == scanf("%d %d",&n, &m)){
		
		if(gcd(n, m) == 1){
			printf("%10d%10d    Good Choice\n\n", n, m);
		}
		else{
			printf("%10d%10d    Bad Choice\n\n", n, m);
		}
	}
	return 0;
}