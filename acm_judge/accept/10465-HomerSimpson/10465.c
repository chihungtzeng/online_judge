#include <stdio.h>
#include <string.h>
#define MAX 10001

int main(){
	short m, n, t;
	short i, j, start;
	short best[MAX];
	while(3 == scanf("%hd %hd %hd", &m, &n, &t)){
		memset(best, 0, sizeof(best[0])*MAX);
		start = (m < n)? m : n;
		best[m] = 1;
		best[n] = 1;
		for(i=start; i<=t; i++){
			if((i >= m) && (best[i-m] + 1 > best[i]) && best[i-m]){
				best[i] = best[i - m] + 1;
			}
			if((i >= n) && (best[i-n] + 1 > best[i]) && best[i-n]){
				best[i] = best[i - n] + 1;
			}
		}
		
		if(best[t]){
			printf("%hd\n", best[t]);
		} else {
			for(i = t - 1; i>=0; i--){
				if(best[i]){
					printf("%hd %hd\n", best[i], t - i);
					break;
				}
			}
			if((i == -1) && (best[0] == 0)){
				printf("0 %hd\n", t);
			}
		} 
	}
	return 0;
}