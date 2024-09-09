#include <stdio.h>
#include <math.h>

double findVolume(long long l, long long w, long long h, double theta){
	double area;
	double tangent;
	tangent = tan(theta);
	if(l*tangent <= h){
		area = l*l*tangent*0.5;
		return area*w;
	}
	else{
		area = (l + l - h/tangent)*h*0.5;
		return area*w;
	}
} 

int main(){
	long long l, w, h;
	double theta;
	double volume;
	const double pi = acos(-1);

	while(4 == scanf("%lld %lld %lld %lf",&l, &w, &h, &theta)){
		
		if(theta == 0){
			volume = 0;
		}
		else if (theta == 90){
			volume = l*w*h;
		} 
		else{
			theta = theta*pi/180;
			
			volume = findVolume(l, w, h, theta);
			volume = l*w*h - volume;
		}
		printf("%.3lf mL\n", volume);
	}
	
	return 0;
}