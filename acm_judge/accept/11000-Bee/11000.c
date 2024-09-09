#include <stdio.h>
#define MAX 4294967296
#define LEN 50

int main(){
	short i;
	long male[LEN];
	long female[LEN];
	long total[LEN];	
	
	male[0] = 0;
	female[0] = 1;
	total[0] = 1;
	for(i=1; i<LEN; i++){
		male[i] = male[i-1] + female[i-1];
		female[i] = male[i-1] + 1;
		total[i] = male[i] + female[i];
	}
	/*printf("%hd years\n",i);*/
	while(1 == scanf("%hd", &i)){
		if(i == -1){
			break;
		}
		printf("%ld %ld\n",male[i], total[i]);
	}	
	
	return 0;
}