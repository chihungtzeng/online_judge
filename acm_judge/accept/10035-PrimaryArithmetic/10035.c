#include <stdio.h>

unsigned long long x, y;
int nCarry, carry;

void findNCarry(){
	nCarry = 0;
	carry = 0;
	int r1, r2 ;
	while((x>0) || (y>0) ){
		
		r1 = x % 10;
		r2 = y % 10;
		carry = (r1 + r2 + carry)/10;
		nCarry += (carry > 0)? 1 : 0;
		x = x/10;
		y = y/10;
	}
	
}

int main(){
	short done=0;
	while(!done){
		scanf("%llu %llu",&x, &y);
		if((x == 0) && (y == 0)){
			done = 1;
			continue;
		}
		findNCarry();
		if(nCarry == 0){
			printf("No carry operation.\n");
		}
		else if (nCarry == 1){
			printf("1 carry operation.\n");
		}
		else {
			printf("%d carry operations.\n",nCarry);
		}
	}
	return 0;
}