#include <stdio.h>

int main(){
	int nCircPrime=42;
	int circPrime[] = {113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 993319, 999331};
	int left,right,ans;
	int i;
	
	while(2 == scanf("%d %d",&left,&right)){
		ans = 0;
		for(i=0;i<nCircPrime;i++){
			if ((circPrime[i] >= left) && (circPrime[i] <= right)){
				ans++;
			}
		}
		if (0 == ans){
			printf("No Circular Primes.\n");
		}
		else {
			printf("%d Circular Primes.\n",ans);
		}
	}
		
}
