#include <stdio.h>
#define DEBUG 0

long sumDigit(long n){
	int r;
	if(n <= 0) return 0;
	
	do{
		r = n % 10;
		n = n / 10;
	}
	while ((r == 0) && (n > 0));
	return r;
}


long dCount(long right){
	/*sum digit from 1 to right*/
	long tmp, nGroup;
	long remainder;
	long ans=0;
	tmp = right;
	
	
	if(right <= 0){
		return 0;
	}
	
		tmp = right;
		while((tmp % 10 != 0) && (tmp > 0)){
				ans += sumDigit(tmp);
				tmp--;
		}
		nGroup = tmp / 10;
		ans = ans + 45 * nGroup;
		ans = ans + dCount(nGroup);
		
		
		if(DEBUG){
			printf("dCount(%ld)= %ld nGroup=%ld\n",right, ans, nGroup);
		}
		return ans;
	
	
}

int main(){
	long left, right;
	long ans;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	while(1){
		fscanf(fp, "%ld %ld", &left, &right);
		if((left < 0) && (right < 0)){
			break;
		}
		
		ans = dCount(right) - dCount(left - 1);
		
		
		printf("%ld\n",ans);
	}

	return 0;
}