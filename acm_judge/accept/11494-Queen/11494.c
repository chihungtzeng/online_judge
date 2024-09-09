#include <stdio.h>
#include <stdlib.h>

char x, y, nx, ny;

char findAns(){
	if( (x == nx) && (y == ny)) return 0;
	if( (x == nx) || (y == ny)) return 1;
	if( abs(x-nx) == abs(y-ny)) return 1;
	
	return 2;
}

int main(){
	
	while(4 == scanf("%hhd %hhd %hhd %hhd",&x, &y, &nx, &ny)){
		if( (x == 0) && (y == 0) && (nx == 0) && (ny == 0)) return 0;
		printf("%hhd\n",findAns());
	}
	return 0;
}
