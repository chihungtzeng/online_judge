#include <stdio.h>
#define MAX 51

int main(){
	short f[MAX], nTest, n;
	
	
	f[1] = 1;
	for(n=2; n<MAX; n++){
		f[n] = f[n-1] +((((n-1) >> 1) + 1) << 1); 
	}	
	
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd", &n);
		printf("%hd\n",f[n]);
	}
	return 0;
}