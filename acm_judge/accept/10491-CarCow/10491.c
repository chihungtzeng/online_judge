#include <stdio.h>

int main(){
	short nCow, nCar, nShow, nDoor;
	
	while(3 == scanf("%hd %hd %hd", &nCow, &nCar, &nShow)){
		nDoor = nCow + nCar;
		printf("%.5lf\n", (0.0 + (nCow + nCar - 1)*nCar)/(nDoor * (nDoor - nShow - 1)));
	}
	return 0;
}