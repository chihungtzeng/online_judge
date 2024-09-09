#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define A 0
#define B 1
#define C 2

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int main(){
	double ell, max, area, areaDouble;
	double cosine[3], sine[3], s;
	double sidesq[3];
	
	short side[3], next[3][2] = {{B, C}, {C, A}, {A, B}};
	short nTest, i;
	
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd %hd %hd",side, side + 1, side + 2);
		qsort(side, 3, sizeof(short), compareShort);
		
		max = 0;
		for(i=0; i<3; i++){
			sidesq[i] = side[i] * side[i]; 
		}
		for(i=0; i<3; i++){
			
			cosine[i] = 
				(double)(sidesq[next[i][0]] + sidesq[next[i][1]] - sidesq[i])/(2.0*side[next[i][0]]*side[next[i][1]]);
			sine[i] = sqrt(1 - cosine[i]*cosine[i]);
			/*printf("side %d: cos=%lf sin=%lf\n", i, cosine[i], sine[i]);*/
		}
		
		s = (side[0] + side[1] + side[2])/2.0 ;
		area = sqrt(s *(s-side[0])*(s-side[1])*(s-side[2]));
		areaDouble = 2*area;
		if(cosine[C] > 0){
			for(i=0; i<3; i++){			
				ell = fabs(areaDouble / (side[i] + side[next[i][1]]*sine[next[i][0]]));
				if(ell > max){
					max = ell;
				}
			}
		}
		else {
			ell = side[A]*sine[B] / (cosine[B] + sine[B]);
			
			max = fabs(ell);
			
			ell = fabs(side[B]*sine[A] / (cosine[A] + sine[A]));
			
			if(ell > max) max = ell;
			
			/*C*/
			ell = areaDouble / (side[C] + side[A]*sine[B]);
			
			if(ell > max) max = ell;
		}
		printf("%.6lf\n", max*max);
	}
	return 0;
}