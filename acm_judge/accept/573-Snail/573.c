#include <stdio.h>
#define EPSILON 1e-12

char h, u, d, f;

short findAns(){
	double cur = 0;
	double forward = u;
	double fatigue = u*(f/100.0);
	
	short day = 1;
	
		
	while(1){
		
		/*printf("Day %hd cur=%lf forward=%lf slide(d)=%hhd fatigue=%lf\n",day, cur,forward, d, fatigue);*/
		cur = cur + forward;
		if(cur >= h + EPSILON){
			return day;
		}
		
		cur = cur - d;
		if(cur < 0) return -day;
		
		day++;		
		forward = forward - fatigue;
		if(forward < 0) forward = 0;
	}
}

int main(){
	short day;
	while(4 == scanf("%hhd %hhd %hhd %hhd", &h, &u, &d, &f)){
		if(0 == h) return 0;
		day = findAns();
		if(day < 0){
			printf("failure on day %hd\n", abs(day));
		}
		else{
			printf("success on day %hd\n",day);
		}
	}
	return 0;
}