#include <stdio.h>

int main(){
	short n, P, Q, nEgg, weight;
	short egg[31];
	short nTest, k = 1, i;
	char done;
	scanf("%hd",&nTest);
	while(k <= nTest){
		scanf("%hd %hd %hd", &n, &P, &Q);
		for(i=0; i<n; i++){
			scanf("%hd", egg + i);
		}
		nEgg = 0;
		weight = 0;
		done = 0;
		for(nEgg=0; (nEgg<n) && (nEgg < P) && (!done); nEgg++){
			if(egg[nEgg] + weight <=  Q){
				weight += egg[nEgg];
			}
			else{
				done = 1;
			}
		}
		if(done){
			nEgg--;
		}
		printf("Case %hd: %hd\n",k++, nEgg);
	}
	return 0;
}