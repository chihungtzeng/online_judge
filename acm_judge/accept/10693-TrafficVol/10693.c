#include <stdio.h>
#include <math.h>

int main(){
	int L, f;
	double vol, speed;
	
	while(2 == scanf("%d %d", &L, &f)){
		if((L == 0) && (f == 0)) break;
		speed = sqrt(2*L*f);
		vol = 1800*speed/L;
		printf("%.8lf %.8lf\n", speed,vol);
	}
	return 0;
}