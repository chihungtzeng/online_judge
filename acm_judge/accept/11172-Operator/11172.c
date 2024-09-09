#include <stdio.h>

int main(){
	int n, m;
	short nTest;
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d",&n, &m);
		if(n < m){
			printf("<\n");
		}
		else if (n > m){
			printf(">\n");
		}
		else{
			printf("=\n");
		}
	}
	return 0;
}