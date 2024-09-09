#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPSILON 1e-12

char pixel[15];
double mini, maxi, preci, minr, maxr, precr;

int findNIteration(double x, double y){
	int count = 0;
	double d = 0;
	double zReal = 0, zImaginary = 0;
	double zRtmp, zItmp;
	
	while((count <= 12) && (d <= 2.0 + EPSILON)){
			count++;
			zRtmp = zReal * zReal - zImaginary * zImaginary;
			zItmp = 2 * zReal * zImaginary;
			zReal = zRtmp + x;
			zImaginary = zItmp + y;
			d = hypot(zReal, zImaginary); 
	}
	return count;
}

void plot(){
	int count;
	double real, imaginary;
	
	
	real = minr; 
	imaginary = mini;
	
	for(imaginary = mini; imaginary <= maxi + EPSILON; imaginary += preci){
		for(real = minr; real <= maxr + EPSILON; real += precr){
			count = findNIteration(real, imaginary);
			if(count <= 12){
				printf("%c", pixel[count - 1]);
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}	
}

int main(){
	char line[15];
	char first = 1;
	int nTest;
	
	
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		scanf("%s %lf %lf %lf %lf %lf %lf", line, &mini, &maxi, &preci, &minr, &maxr, &precr);
		strncpy(pixel, line + 1, 12); 
		plot();
	}
	
		
	return 0;
}