#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0

int compareDouble(const void *a, const void *b){
	double x, y;
	x = *(double *)a;
	y = *(double *)b;
	if(x < y) return -1;
	else if (x > y) return 1;
	else return 0;
}

int main(){
	char nFrontSprocket, nRearSprocket;
	char i, j;
	double drive[128];
	char fgear[16], rgear[16];
	short nDrive, k;
	double ans;
	
	while(1 == scanf("%hhd", &nFrontSprocket)){
		if(0 == nFrontSprocket) break;
		
		scanf("%hhd", &nRearSprocket);
		for(i=0; i<nFrontSprocket; i++){
			scanf("%hhd", fgear + i);
		}
		for(i=0; i<nRearSprocket; i++){
			scanf("%hhd", rgear + i);
		}
		if(DEBUG){
			for(i=0; i<nFrontSprocket; i++){
				printf("%hhd ", fgear[i]);
			}
			puts("");
			for(i=0; i<nRearSprocket; i++){
				printf("%hhd ", rgear[i]);
			}
			puts("");
		}
		
		nDrive = 0;
		for(i=0; i<nFrontSprocket; i++){
			for(j=0; j<nRearSprocket; j++){
				drive[nDrive++]  = (rgear[j] + 0.0) / fgear[i];
			}
		}
		qsort(drive, nDrive, sizeof(double), compareDouble);
		ans = -1;
		for(k=nDrive - 1; k >= 1; k--){
			if( drive[k] / drive[k-1] > ans){
				ans = drive[k] / drive[k-1];
			} 
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}