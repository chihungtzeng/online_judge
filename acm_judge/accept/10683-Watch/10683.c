#include <stdio.h>

int main(){
	short hh,mm,ss,cc;
	long secOfDay;
	short HH, MM, SS, CC;
	while(4 == scanf("%2hd%2hd%2hd%2hd", &hh, &mm, &ss, &cc)){
		secOfDay = (long)hh*360000 + mm*6000 + ss*100 + cc;
		secOfDay = (secOfDay*1000)/864;
		CC = secOfDay % 100;
		secOfDay = (secOfDay - CC) / 100;
		SS = secOfDay % 100;
		secOfDay = (secOfDay - SS) / 100;
		MM = secOfDay % 100;
		secOfDay = (secOfDay - MM) / 100;
		HH = secOfDay;
		printf("%hd%02hd%02hd%02hd\n",HH,MM,SS,CC);
	}
	return 0;
}