#include <stdio.h>

unsigned long long gcd(unsigned long long a, unsigned long long b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int output(unsigned long long x, unsigned long long y, short k){
	short len=0;
	unsigned long tmp;
	tmp = y;
	while(tmp > 0){
		len++;
		tmp = tmp / 10;
	}
	printf("Case %hd:\n",k);
	printf("%llu\n",x);
	while(len >= 1){
		printf("-");
		len--;
	}
	printf("\n%llu\n\n",y);
	return 0;
}

int main(){
	unsigned long long n, m, up[4], down[4], g, x, y;
	short i, j, k=1;
	
	while(2 == scanf("%llu %llu", &n, &m)){
		if((0 == n) && (0 == m)) break;
		
		up[0] = n;
		up[1] = n*n + 6*n + 11;
		up[2] = m;
		up[3] = m*m + 6*m + 11;
		down[0] = 18*(n + 1);
		down[1] = (n + 2)*(n+3);
		down[2] = 18*(m + 1);
		down[3] = (m + 2)*(m + 3);
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				g = gcd(up[i], down[j]);
				if(g > 1){
					up[i] = up[i]/g;
					down[j] = down[j]/g;
				}
			}
		}
		x = up[0];
		y = down[0];
		for(i=1; i<4; i++){
			x = x*up[i];
			y = y*down[i];
		}
		output(x, y, k);
		k++;
	}
	return 0;
}