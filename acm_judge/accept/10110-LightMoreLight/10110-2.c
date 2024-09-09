#include <stdio.h>

int main(){
	unsigned long int num,sq;
	int i,found,done,nbit;
	unsigned long int left,right,middle,square;
	done = 0;
	while(!done){
		scanf("%ld",&num);
		if ( 0 == num ){
			done = 1;
			continue;
		}
		right = 1;
		nbit = 1;
		while ( right < num ){
			nbit++;
			right = 1 << nbit;
		}
		left = 0 ;
		right = 1 << (nbit/2) ;
		
		found = 0;
		while((left <= right) && (!found)){
			middle = (left + right) >> 1;
			square = middle * middle;
			if (square == num ){
				found = 1;
				continue;
			}
			else if (square > num){
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		
		if (found) {
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
	 
	return 0;
}