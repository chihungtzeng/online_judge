/*AC 0.044*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 6000
#define DEBUG 0

struct Frac{
	long long up, down;
	double output;
	double diff;
};

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

void swapFrac(struct Frac *a, struct Frac *b){
	struct Frac tmp;
	memcpy(&tmp, a, sizeof(struct Frac));
	memcpy(a, b, sizeof(struct Frac));
	memcpy(b, &tmp, sizeof(struct Frac));
}

int compareFrac(const void *a, const void *b){
	struct Frac *x, *y;
	int result;
	x = (struct Frac *)a;
	y = (struct Frac *)b;
	result = compareDouble(&(x->diff), &(y->diff));
	if(result != 0) return result;
	if (x->up != y->up) return x->up - y->up;
	else return x->down - y->down;
}


int compareDouble(const void *a, const void *b){
	double x, y;
	x = *(double *)a;
	y = *(double *)b;
	if(x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

int setFrac(struct Frac *f, int up, int down, double d){
	f->output = (double) up / down;
	f->up = up;
	f->down = down;
	f->diff = fabs(f->output - d);
	return EXIT_SUCCESS;
}

void doubleToString(char sOutput[], double d){
	char longOutput[32];
	int len;
	long long damn;
	double dabs;
	if(d >= 0){
		damn = (long long)d;
		if(damn >= 1000000000){
			sprintf(sOutput, "%lld", damn);
		}
		else{
			len = sprintf(longOutput, "%lld", damn);
			sprintf(sOutput, "%.*lf",10-len, d);
		}
	}
	else{
		damn = (long long)fabs(d);
		len = sprintf(longOutput, "%lld", damn);
		sprintf(sOutput, "%.*lf",10-len, d);
	}
}

int main(){
	struct Frac frac[4];
	
	long long i, j, x, y, xplus, xminus, xx, yy, g, xplus2, xminus2;
	long long offset;
	double input;
	char sOutput[12];
	
	
	
	while(1 == scanf("%lf",&input)){
		if(input <= 0){
			doubleToString(sOutput, input);
			printf("Input : %s\n",sOutput);
			puts("    1 : 0.001000000 =    1 / 1000");
   		puts("    2 : 0.001001001 =    1 / 999");
    		puts("    3 : 0.001002004 =    1 / 998");
    		continue;
		}
		else if(input >= 1000){
			doubleToString(sOutput, input);
			printf("Input : %s\n",sOutput);
			puts("    1 : 1000.000000 = 1000 / 1");
    		puts("    2 : 999.0000000 =  999 / 1");
    		puts("    3 : 998.0000000 =  998 / 1");
    		continue;
    	}
		
		frac[0].diff = 10000;
		frac[1].diff = 10000;
		frac[2].diff = 10000;		

		for(y = 1; y <= 1000; y++){
			x = input * y;
			for(offset = -2; offset <= 2; offset++){
				xx = x + offset;
				
				if((xx < 1) || (xx  > 1000)) continue;
				g = gcd(xx, y);
				if(g != 1) continue;
				
				setFrac(&frac[3], xx, y, input);
				for(j=0; j<3; j++){
					if(frac[j].diff > frac[3].diff){
						swapFrac(frac + j, frac +3);
					}
				}
			}
			
		}

		
		doubleToString(sOutput, input);
		
		printf("Input : %s\n",sOutput);
		
		doubleToString(sOutput, frac[0].output);
		
		printf("    1 : %s = %4lld / %lld\n", sOutput, frac[0].up, frac[0].down);
		
		for(i=1; i<=2; i++){
				doubleToString(sOutput, frac[i].output);
				printf("    %lld : %s = %4lld / %lld\n", i + 1, sOutput, frac[i].up, frac[i].down);
		}
	}
	
	return 0;
}