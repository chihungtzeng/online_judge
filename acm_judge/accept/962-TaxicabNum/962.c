#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int compareLong(const void *x, const void *y){
	return *(long *)x - *(long *)y; 
}

int main(){
	long cube[MAX];
	long cab[1600];
	long cab2[1600];
	int nCabNum,nCab2;
	int i,j,x,y;
	long cabnum, remains;
	long *match;
	
	for(i=1;i<MAX;i++){
		cube[i] = i*i*i;
	}
	nCabNum=0;
	for(i=1;i<=MAX-4;i++){
		for(j=i+3;j<MAX;j++){
			for(x = i+1; x<=j-2; x++){
				
				cabnum = cube[i] + cube[j];
				if(cabnum <= 1000100000){
					remains = cabnum - cube[x];
					match = (long *) bsearch(&remains, cube+x,MAX-x+1,sizeof(long),compareLong);
					if (match != NULL){
						//printf("Find cab number %ld\n",cabnum);
						cab[nCabNum] = cabnum;
						nCabNum++;
					}
				}
			}
		}
	}	
	//printf("Find %d cab numbers \n",nCabNum);
	qsort(cab,nCabNum,sizeof(long),compareLong);
	nCab2=0;
	cab[nCabNum]=0;
	for(i=0;i<nCabNum;i++){
		if(cab[i]!=cab[i+1]){
			cab2[nCab2++] = cab[i];
		}
	}
	printf("int cab[]={");
	for(i=0;i<nCab2;i++){
		printf("%ld, ",cab2[i]);
		if(i % 100 == 0){
			printf("\n");
		}
	}
	printf("};");
	printf("%d cab numbers\n",nCab2);
	
	return 0;
}