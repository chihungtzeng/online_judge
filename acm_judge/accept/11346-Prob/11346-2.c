#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define EPSILON 1e-323
#define LINELEN 10000

int main(){
	short nTest;
	double a, b, S, prob, area;
	char line[LINELEN];
	char *s;
	FILE *fp;
	
	fp = stdin;
	fgets(line, LINELEN, fp);
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		fgets(line, LINELEN, fp);
		
		a = atof(strtok(line, " \n"));
		b = atof(strtok(NULL, " \n"));
		S = atof(strtok(NULL, " \n"));
		

		if(S <= EPSILON){
			prob = 1.0;
		}		
		else{
			area = (a - S/b)*b;
			area = area - S*(log(a) +log(b) -log(S));
			prob = (area/a)/b;
		}
		
		prob = prob * 100.0;
		printf("%.6lf%%\n",prob);
	}
	return 0;
}
