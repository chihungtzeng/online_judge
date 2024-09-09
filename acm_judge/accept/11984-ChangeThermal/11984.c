#include <stdio.h>

int main(){
	char nTest, k = 1, C;
	short F;
	double ans;
	scanf("%hhd", &nTest);
	while(nTest > 0){
		nTest--;
		scanf("%hhd %hd", &C, &F);
		F = (F << 2) + F + (C << 3) + C;
		ans = F/9.0;
		printf("Case %hhd: %.2lf\n", k++, ans);
	}
	return 0;
}