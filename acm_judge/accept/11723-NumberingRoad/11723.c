#include <stdio.h>

int main(){
	int r, n;
	int k=1, q;
	while(2 == scanf("%d %d", &r, &n)){
		if((r == 0) && (n == 0)) return 0;
		q = r / n;
		if(r % n == 0) q--;
		if(q > 26){
			printf("Case %d: impossible\n", k);
		}
		else{
			printf("Case %d: %d\n", k, q);
		}
		k++;
	}
	return 0;
}