#include <stdio.h>
#include <math.h>

int main(){
	double num;
	num = (log(100) - log(10)) / log(1.6);
	printf("%f \n",num);
	num = (log(9876543210) - log(1234567890)) / log(1.6);
	printf("%f \n",num);
}

