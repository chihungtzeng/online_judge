#include <stdio.h>
#include <stdlib.h>
#include <search.h>

short digitSquare[10];

int *newInt(int x){
	int *p;
	p = (int *) malloc(sizeof(int));
	*p = x;
	return p;
}

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int digitSquareSum(int n){
	int result = 0;
	int digit;
	while(n > 0){
		digit = n % 10;
		n = n / 10;
		result += digitSquare[digit];
	}
	return result;
}

int isHappyNumber(int n){
	int *pInt;
	void *root = NULL, *match;
	int ret;
	tsearch(newInt(n), &root, compareInt);
	while(1){
		n = digitSquareSum(n);
		if(1 == n){
			ret = 1;
			break;
		} 
		pInt = newInt(n);
		match = tsearch(pInt, &root, compareInt);
		if(*(int **)match != pInt) {
			ret = 0;
			break;
		} 
	}
	tdestroy(root, free);
	return ret;
}

int main(){
	int k=1, nTest;
	int n;
	for(n=0; n<10; n++){
		digitSquare[n] = n*n;
	}
	scanf("%d", &nTest);
	while(nTest--){
		scanf("%d", &n);
		if(isHappyNumber(n)){
			printf("Case #%d: %d is a Happy number.\n", k++, n);
		} else {
			printf("Case #%d: %d is an Unhappy number.\n", k++, n);
		}
	}
	return 0;
}