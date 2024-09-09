#include <stdio.h>
#include <string.h>
#define LEN 20
#define SWAP(a, b) (a) = (a) ^ (b); (b) = (a) ^ (b); (a) = (a) ^ (b)

int compareChar(const void *a, const void *b){
	return *(char *)a - *(char *)b;
}

void reverse(char *ptr, char len){
	char *head, *tail;
	head = ptr;
	tail = ptr + len - 1;
	while(head < tail){
		SWAP(*head, *tail);
		head++;
		tail--;
	}
}

long long myatoll(char *p){
	long long result = 0;
	while(*p != '\0'){
		result = result * 10 + (*p - '0');
		p++;
	}
	return result;
}

void solve(long long n){
	char szInc[LEN], szDec[LEN];
	char len, i;
	long long x, y, result, divisor; /*result = x - y = 9 * divisor*/
	len = sprintf(szInc, "%lld", n);
	qsort(szInc, len, sizeof(char), compareChar);
	strcpy(szDec, szInc);
	reverse(szDec, len);
	i = 0;
	while((i < len) && (szInc[i] == '0')){
		i++;
	}
	if(i > 0){
		SWAP(szInc[0], szInc[i]);
	}
	x = myatoll(szDec);
	y = myatoll(szInc);
	#if 0
	printf("x=%lld , y=%lld\n", x, y);
	#endif
	result = x - y;
	divisor = result / 9;
	printf("%s - %s = %lld = 9 * %lld\n", szDec, szInc, result, divisor);
}

int main(){
	long long n;
	while(1 == scanf("%lld", &n)){
		solve(n);
	}
	return 0;
}