#include <stdio.h>

int main(){
	int x,y;
	x = 10; y =3;
	printf("%d mod %d = %d\n", x, y, x % y);
	x = -10; y =3;
	printf("%d mod %d = %d\n", x, y, x % y);
	x = 10; y =-3;
	printf("%d mod %d = %d\n", x, y, x % y);
	x = -10; y =-3;
	printf("%d mod %d = %d\n", x, y, x % y);
}
