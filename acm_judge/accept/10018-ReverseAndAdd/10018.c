#include <stdio.h>
#define YES 1
#define NO 0

int ifPalindrome(long n){
	short s[13];
	short len = 0, i;
	if(n == 0) return YES;	
	while(n > 0){
		s[len++] = n % 10;
		n = n / 10;
	}
	for(i = (len >> 1) - 1; i>=0; i--){
		if(s[i] != s[len -i -1]){
			return NO;
		}
	}
	return YES;
}

long reverse(long n){
	long result=0;
	if(n == 0) return 0;
	while(n > 0){
		result = result*10 + (n % 10);
		n = n/10;
	}
	return result;
}

int main(){
	int nTest, count;
	long inNum;
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%ld",&inNum);
		count = 0;
		while(!ifPalindrome(inNum)){
			inNum += reverse(inNum);
			count++; 
		}
		printf("%d %ld\n",count,inNum);
	}
	return 0;
}