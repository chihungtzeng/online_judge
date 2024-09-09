#include <stdio.h>
#define MAX 13
#define LEN 10
char fac[MAX][LEN] = {"1","1","2","6","24","120","720","5040","40320","362880","3628800","39916800","479001600",};
char ans[MAX][LEN] = {"0","1","1","2","9","44","265","1854","14833","133496","1334961","14684570","176214841",};


int main(){
	short nTest, i;
	char output[32];
	
	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%hd", &i);
		sprintf(output, "%s/%s", ans[i], fac[i]);
		puts(output);
	}
	
	return 0;
}
