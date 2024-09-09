#include <stdio.h>

int nTerm(long long start, long long limit){
	int count = 1;
	while((start <= limit) && (start != 1)){
		start = (start & 1)? 
			(start + (start << 1) + 1) : (start >> 1);
		++count;
	} 
	if(start > limit) count--;
	return count;
}

int main(){
	long long start, limit;
	int k=1;
	while(2 == scanf("%lld %lld", &start, &limit)){
		if((start < 0) && (limit < 0)) {
			break;
		}
		else {
			printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", k++, start, limit, nTerm(start, limit));
		}
	}
	return 0;
}