#include<stdio.h>
#define MAX 10005

int main(){
	int sample[MAX], nSample, i;
	int peak;	
	while(1 == scanf("%d", &nSample)){
		if(0 == nSample) break;
		
		for(i=1; i<=nSample; i++){
			scanf("%d", sample + i);
		}
		sample[0] = sample[nSample];
		sample[nSample + 1] = sample[1];
		peak = 0;
		for(i=1; i<=nSample; i++){
			if( 
				((sample[i] > sample[i-1]) && (sample[i] > sample[i+1])) ||
				((sample[i] < sample[i-1]) && (sample[i] < sample[i+1]))
				){
				peak++;
			} 
		}
		printf("%d\n",peak);
	}
	return 0;
}