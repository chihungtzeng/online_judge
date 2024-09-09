#include <stdio.h>
#define MAX 100000000

long long nDiagonal(long long n){
	return (n*(n-1) >> 1) - n;
}

long long findAns(long long nEdge){
	long long middle, left, right;
	long long x, y;
	left = 1;
	right = 1;
	while(nDiagonal(right) <= nEdge){
		right = right*2;
	}
	while(left <= right){
		middle = (left + right) >> 1;
		x = nDiagonal(middle);
		y = nDiagonal(middle + 1);
		if( (nEdge > x) && (nEdge <= y)){
			return middle + 1;
		}
		else if (nEdge < x){
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return 0;
}


int main(){
	long long nEdge, ans;
	short k=1;
	while(1 == scanf("%lld",&nEdge)){
		if(0 == nEdge){
			break;
		}
		ans = findAns(nEdge);
		printf("Case %hd: %lld\n",k++, ans);
	}
	return 0;
}