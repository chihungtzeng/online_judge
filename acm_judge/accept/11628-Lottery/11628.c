#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

/*
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}
*/
int bgcd(int a, int b){
	int tmp;
	if(b == 0) return a;
	else if (a == 0) return b;
	
	if((a & 1) && (b & 1)){
		if(a > b) return bgcd(a - b, b);
		else return bgcd(b - a, a);
	}
	else if ((a & 1) && (!(b & 1))){
		return bgcd(a, b >> 1);
	}
	else if ((!(a & 1)) && ((b & 1))){
		return bgcd(a >> 1, b);
	}
	else {
		return bgcd(a >> 1, b >> 1) << 1;
	}
}
int gcd(int a, int b){
	int shiftAmount = 0;
	int c = 0;
	int w;
	while( (!(a & 1)) && (!(b & 1))){
		a = a >> 1;
		b = b >> 1;
		shiftAmount++;
	}

	if(!(a & 1)){
		/*a is even, switch with b so that a becomes odd*/
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}	
	while(b != 0){
		while(!(b & 1)){
			b = b >> 1;
			c++;
		}
		/*Now b is odd*/
		if(c > 0){
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
			c = -c;
		}
		w = (a + b) >> 1;
		if(w & 1){
			b = w - b;
		}
		else{
			b = w;
		}
	}
	return abs(a) << shiftAmount;
}

int main(){
	int n, m;
	int ticket[MAX];
	int i, j, g, nTicket;
	
	while(1){
		scanf("%d %d", &n, &m);
		if((n == 0) && (m == 0)){
			break;
		}
		nTicket = 0;
		for(i=1; i<= n; i++){
			for(j = 1; j <= m - 1; j++){
				scanf("%d", &ticket[i]);
			}
			scanf("%d", &ticket[i]);
			nTicket += ticket[i];
		}
		for(i=1; i<=n; i++){
			g = bgcd(nTicket, ticket[i]);
			printf("%d / %d\n", ticket[i]/g, nTicket/g);
		}
	}	
	
	return 0;
}
