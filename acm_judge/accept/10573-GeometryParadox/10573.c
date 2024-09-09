#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LEN 32
int main(){
	int r1, r2;
	int nTest, nTok;
	char line[LEN];
	FILE *fp = stdin;
	
	const double piover8 = M_PI / 8.0;
	const double pi2 = M_PI * 2.0;
	double area;
	fgets(line, LEN, fp);
	nTest = atoi(line);
	while(nTest--){
		fgets(line, LEN, fp);
		nTok = sscanf(line, "%d %d", &r1, &r2);
		if(2 == nTok){
			area = pi2*r1*r2;
		} else {
			area = piover8*r1*r1;
		}
		printf("%.4lf\n", area);
	}
	return 0;
}