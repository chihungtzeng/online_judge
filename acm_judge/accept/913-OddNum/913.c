#include <stdio.h>

int main(){
	long int x,y,ans;
	
	while(1 == scanf("%ld",&x)){
		y= (x+1)/2;
		ans = 6*y*y - 9;
		printf("%ld\n",ans);
	}
	return 0;
}