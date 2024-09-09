#include <stdio.h>
#include <math.h>

int main(){
	int EV1, EV2, AT, D;
	int n1, n2;
	double p1, p2;
	double p, q;
	double t1, t2, x;
	while(4 == scanf("%d %d %d %d", &EV1, &EV2, &AT, &D)){
		if(0 == EV1 + EV2 + AT + D) return 0;

		n1 = (EV1 / D);
		if(EV1 % D != 0) n1++;
		n2 = (EV2 / D);
		if(EV2 % D != 0) n2++;
				
		if(AT == 3){
			p1 = (n1 + 0.0) / (n1 + n2);
		}
		else{
			x = (6.0 - AT) / AT;
			t1 = pow(x, n1);
			t2 = pow(x, (n1 + n2)); 
			p1 = (1.0 - t1)/(1.0 - t2);
		}
		printf("%.1lf\n", 100*p1);
	}
	return 0;
}