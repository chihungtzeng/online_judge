#include <stdio.h>
#define DEBUG 0
#define LEN 2001
#define MAX(a, b) (((a) < (b))? (b) : (a))

void calcLIS(short Seq[], short nCar, int car[]){
	/*find the LIS starting from i for 0 <= i < nCar*/
	short i, j;
	
	for(i=nCar - 1; i>=0; i--){
		Seq[i] = 1;
		for(j=nCar - 1; j>i; j--){
			if(car[j] > car[i]){
				Seq[i] = MAX(Seq[i], Seq[j] + 1);
			}
		}
	}
	#if DEBUG
	printf("LIS:");
	for(i=0; i<nCar; i++){
		printf("%hd ", Seq[i]);
	}
	printf("\n");
	#endif
}

void calcLDS(short Seq[], short nCar, int car[]){
	/*find the LDS starting from i for 0 <= i < nCar*/
	short i, j;
	for(i=nCar - 1; i>=0; i--){
		Seq[i] = 1;
		for(j=nCar - 1; j>i; j--){
			if(car[j] < car[i]){
				Seq[i] = MAX(Seq[i], Seq[j] + 1);
			}
		}
	}
	#if DEBUG
	printf("LDS:");
	for(i=0; i<nCar; i++){
		printf("%hd ", Seq[i]);
	}
	printf("\n");
	#endif
}



int main(){	
	short LIS[LEN];
	short LDS[LEN];
	int car[LEN];
	short ans;
	short nTest, nCar, i;
	scanf("%hd", &nTest);
	while(nTest > 0){
		nTest--;
		scanf("%hd", &nCar);

		if(nCar == 0){
			puts("0");
			continue;
		}		
		
		for(i=0; i<nCar; i++){
			scanf("%d", car + i);
		}
		calcLIS(LIS, nCar, car);
		calcLDS(LDS, nCar, car);
		
		
		ans = 0;
		for(i=0; i<nCar; i++){
			if(LIS[i] + LDS[i] > ans){
				ans = LIS[i] + LDS[i];
			}
		}
		printf("%hd\n", ans - 1);
	}
	return 0;
}