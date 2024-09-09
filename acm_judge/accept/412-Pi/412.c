#include <stdio.h>
#include <math.h>

short gcd(short a, short b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(){
	short n,i,j,count;
	short num[51];
	double estimate;
	
	while(1 == scanf("%hd",&n)){
		if(0 == n) break;
		
		for(i=n-1; i>=0; i--){
			scanf("%hd", num + i);
		}
		count = 0;
		for(i=0; i<n; i++){
			for(j=i+1; j<n; j++){
				count += (gcd(num[i], num[j]) == 1)? 1 : 0;
			}
		}
		if(count == 0){
			puts("No estimate for this data set.");
		}
		else{
			estimate = sqrt( (3.0 * n*(n-1)) / count);
			printf("%.6lf\n",estimate);
		}
	}
	return 0;
}