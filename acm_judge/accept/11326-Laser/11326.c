#include <stdio.h>
#include <math.h>

int main(){
	int nTest;
	double A, B;
	double L, W, theta;
	double remain, section;
	double tantheta;
	double toRadius = acos(-1.0) / 180.0;
	int nReflect;
	
	
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%lf %lf %lf", &L, &W, &theta);

		if(theta == 0.0){
			printf("1.000\n");
			continue;
		}
		else if (theta == 90.0){
			printf("0.000\n");
			continue;
		}

		theta = theta * toRadius;
		tantheta = tan(theta);
		/*printf("L=%lf W=%lf theta=%lf\n",L,W,theta);*/
		section = W / tantheta;		
		nReflect = L / section;
		
		
		remain = L - nReflect*section;
		if(nReflect & 1){
			B = W - remain*tantheta;
				
		}
		else{
			B = remain * tantheta;
		}		
		B = sqrt(B*B + L*L);
		A = L / cos(theta);
		printf("%.3lf\n",A/B);
	}
	return 0;
}