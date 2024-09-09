#include <stdio.h>
int main(){
	int n, m, nTest;
	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d",&n, &m);
		if(m % n == 0){
			printf("%d %d\n", n, m);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}