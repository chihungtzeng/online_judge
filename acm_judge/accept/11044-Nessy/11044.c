#include <stdio.h>


int main(){
	short nTest;
	int n, m, x, y;
	
	scanf("%hd", &nTest);
	
	while(nTest >= 1){
		nTest--;
		scanf("%d %d", &n, &m);
		x = (n - 2)/3;
		if( n - 2 - x - (x << 1) > 0 ) x++;
		
		y = (m - 2)/3;
		if(m -2 - y - (y << 1) > 0) y++;
		
		printf("%d\n", x*y);
	}	
	
	return 0;
}