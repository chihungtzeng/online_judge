#include <stdio.h>
#define MAX 501

unsigned short gcd(unsigned short a, unsigned short b){
	if (b==0) return a;
	else return gcd(b, a%b);
} 

int main(){
	int sum;
	unsigned short gcdtable[MAX][MAX];
	unsigned short i, j, input;
	
	for(i=0;i<MAX;i++){
		for(j=i;j<MAX;j++){
			gcdtable[i][j] = gcd(i,j);
		}
	}	
	
	while((1 == scanf("%hd",&input)) && (input != 0)){
		sum = 0;
		for(i =1; i<input; i++){
			for(j=i+1;j<=input;j++){
				sum += gcdtable[i][j];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}