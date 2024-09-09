#include <stdio.h>
#include <string.h>

int Joseph(int n, int m){
	int ans=0, i;
	for(i=1; i<=n ; i++){
		ans = (ans + m) % i;
	} 
	return ans;
}

int findAns(int n){
	int m;
	
	for(m=1; ; m++){
		if((Joseph(n, m) + (n << 10) - m + 2) % n == 13) return m;
	}
	return -1;
}

int main(){
	int n;
	
	
	while(1 == scanf("%d",&n)){
		if(0 == n) break;
		if(n == 13){
			printf("1\n");
		}
		else{
			printf("%d\n",findAns(n));
		}
	}
	
	return 0;
}