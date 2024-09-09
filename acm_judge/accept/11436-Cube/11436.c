/*AC 0.364s*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DEBUG 0
#define MAX 100000
#define BOUND 29240

long long x, y, a, b;
long long cube[BOUND];

long long mysqrt(long long d){
	long long x;
	x = sqrt(d);
	if(x*x == d) return x;
	else return -1;
}

long long findy(long long a, long long b){
	long long d;
	long long asq;
	asq = (long long)a*a;
	
	d = (asq << 3) + asq - ((asq - b) << 3) - ((asq - b) << 2);
	 
	if(d < 0) return -1;
	d = mysqrt(d);
	if(d < 0) return -1;
	d = d - a - (a << 1);
	d = d/6;
	return d;
}

int main(){
	
	
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	

	
	
	long long input;
	long long xc, yc;
	char found;
	
	for(a=1; a<BOUND; a++){
		cube[a] = a*a*a;
	}	
	while(1 == fscanf(fp, "%lld", &input)){
		if(input == 0) return 0;
		found = 0;

		for(a = 1; (!found) && (cube[a] <=input); a++){
			if(input % a != 0) continue;
			b = input / a;
			y = findy(a, b);
			x = a + y;
			if( (x <= 0) || (y <= 0)) continue;
			xc = x*x*x;
			yc = y*y*y;
			if((xc - yc == input)){
				found = 1;
			}
		}		
		
		if(found){			
			printf("%lld %lld\n",x, y);
		}
		else{
			puts("No solution");
		}
	}
	
	return 0;
}