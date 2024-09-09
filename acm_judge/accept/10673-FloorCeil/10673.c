#include <stdio.h>

int main(){
	short nTest;
	int x, y, k, p, q;
	
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d", &x, &k);
		y = x / k;
		if(y > 0){
			if(x % k == 0){
				p = (x / y) / 2;
				q = (x / y) - p;
			}
			else{
				q = x % y;
				p = (x / y) - q;
			}
		}
		else {
			p = 0;
			q = x;
		}
		printf("%d %d\n", p, q);
	}
	
	return 0;
}