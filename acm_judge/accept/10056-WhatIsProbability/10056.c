#include <stdio.h>
#include <math.h>


int main(){
	int nTest, nPeople, k; 
	double p, q; /*p + q = 1;*/
	double ans, tmp;
	
	scanf("%d\n",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %lf %d", &nPeople, &p, &k);
		q = 1 - p;
		tmp = 1 - pow(q, nPeople);
		if( tmp == 0.0){
			ans = 0;
		}
		else{
			ans = pow(q, k-1)*p / tmp;
		}
		printf("%0.4lf\n", ans);
	}

	return 0;
}