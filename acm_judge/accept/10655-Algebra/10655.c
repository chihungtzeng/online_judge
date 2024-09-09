#include <stdio.h>
#define DEBUG 0
#define LEN 1024

long long mypow(int a, int p){
	long long ans;
	if(p == 0) return 1;
	if(p == 1) return a;
	ans = mypow(a, p >> 1);
	ans = ans * ans;
	if(p & 1){
		ans = ans * a;
	}
	return ans;
}

long long solve(int plus, int multiply, int p){
	long long ans;
	if(p == 0) return 2;
	if(p == 1) return plus;
	
	if(p & 1){
		long long middleup, middledown;
		middledown = p >> 1;
		middleup = middledown + 1;
		middledown = solve(plus, multiply, middledown);
		middleup = solve(plus, multiply, middleup);
		ans = middledown * middleup - plus * mypow(multiply, p >> 1);
	}
	else{
		ans = solve(plus, multiply, p >> 1);
		ans = ans * ans;
		ans = ans - (mypow(multiply, p >> 1) << 1);
	}
	return ans;
} 

int main(){
	int plus, multiply, p, nRead;
	long long ans;
	FILE *fp;
	char line[LEN];
	
	fp = (DEBUG)? fopen("in3.txt", "r") : stdin;
	
	while(NULL != fgets(line, LEN, fp)){
		nRead = sscanf(line, "%d %d %d", &plus, &multiply, &p);
		if(3 != nRead) return 0;
		ans = solve(plus, multiply, p);
		printf("%lld\n",ans);
	}
	return 0;
}