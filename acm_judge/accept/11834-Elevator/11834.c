#include <stdio.h>


short min(short a, short b){
	if(a < b) return a;
	else return b;
}

short max(short a, short b){
	if(a > b) return a;
	else return b;
}

int main(){
	short L, C, R1, R2;
	short sum;
	int y1, x2, diag;
	while(4 == scanf("%hd %hd %hd %hd",&L, &C, &R1, &R2)){
		if( (L == 0) && (C == 0) && (R1 == 0) && (R2 == 0)) return 0;
		y1 = C - R1;
		x2 = L - R2;
		sum = R1 + R2;
		sum = sum*sum;
		diag = (R1 - x2)*(R1 - x2) + (y1 - R2)*(y1 - R2);
		/*(r1+r2 <= sqrt(aux1+aux2)) && ((max(r1,r2)*2) <= min(l,h)*/
		if( (sum <= diag) && (max(R1, R2)*2 <= min(L,C)) ){
			puts("S");
		} 
		else{
			puts("N");
		}
	}
	return 0;
}