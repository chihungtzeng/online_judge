#include <stdio.h>

union{
   int data;
   char bit[4];
}x, y;

int main(){
	while(1 == scanf("%d",&x.data)){
		y.bit[3]=x.bit[0];
	   y.bit[0]=x.bit[3];
	   y.bit[1]=x.bit[2];
	   y.bit[2]=x.bit[1];
	   printf("%d converts to %d\n", x.data, y.data);	
	}
	return 0;
}