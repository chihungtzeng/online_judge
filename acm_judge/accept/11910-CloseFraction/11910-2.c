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
	struct Frac frac[MAX];
	int nFrac;
	long long i, x, y, xplus, xminus, xx, yy, g, xplus2, xminus2;
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
		
		
		nFrac = 0;
		for(y = 1; y <= 1000; y++){
			x = input * y;
			xplus = x + 1;
			xminus = x - 1;
			xplus2 = x + 2;
			xminus2 = x - 2;
			
			if((x <= 1000) && (x >= 1)){
				setFrac(frac + nFrac, x, y, input);
				nFrac++;
			}
			if(xplus <= 1000){
				setFrac(frac + nFrac, xplus, y, input);
				nFrac++;
			}
			if(xminus <= 1000){
				setFrac(frac + nFrac, xminus, y, input);
				nFrac++;
			}
			if(xplus2 <= 1000){
				setFrac(frac + nFrac, xplus2, y, input);
				nFrac++;
			}
			if(xminus2 <= 1000){
				setFrac(frac + nFrac, xminus2, y, input);
				nFrac++;
			}
			
		}
		qsort(frac, nFrac, sizeof(struct Frac), compareFrac);
		if(DEBUG){
			for(i=0; i<nFrac; i++){
				printf("frac %lld: output: %lf up=%lld down = %lld diff=%lf\n", i, frac[i].output, frac[i].up, frac[i].down, frac[i].diff);
			}
			
		}
		
		doubleToString(sOutput, input);
		
		printf("Input : %s\n",sOutput);
		g = gcd(frac[0].up, frac[0].down);
		if(g != 1){
			frac[0].up = frac[0].up / g;
			frac[0].down = frac[0].down / g;
		}
		doubleToString(sOutput, frac[0].output);
		
		printf("    1 : %s = %4lld / %lld\n", sOutput, frac[0].up, frac[0].down);
		
		i = 1;
		x = 0;
		while((x < 2) && (i<nFrac)){
			g = gcd(frac[i].up, frac[i].down);
			if(g != 1){
				i++;
			}
			else{
				frac[i].up /= g;
				frac[i].down /= g;
				doubleToString(sOutput, frac[i].output);
				printf("    %lld : %s = %4lld / %lld\n", x + 2, sOutput, frac[i].up, frac[i].down);
				i++;
				x++;
			}
		}
	}
	
	return 0;
}