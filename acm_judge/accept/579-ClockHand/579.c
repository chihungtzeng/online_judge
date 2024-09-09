#include <stdio.h>


int main(){
	char HH, MM;
	short mAngle, hAngle;
	double ans;
	
	while(2 == scanf("%hhd:%hhd",&HH,&MM)){
		if ((HH == 0) && (MM == 0)) return 0;
		HH = HH % 12;
		mAngle = MM * 12;
		hAngle = HH * 60 + MM;
		/*printf("angle minute:%hd hour:%hd\n",mAngle, hAngle);*/
		ans = hAngle - mAngle;
		ans = ans/2;
		if(ans < 0) ans = -ans;
		if(ans > 180) ans = 360 - ans;
		
		printf("%.3lf\n",ans);
	}
	return 0;
}