#include <stdio.h>
#include <string.h>
#define MAX 500001
#define DEBUG 0

long long mergeSort(int a[], int len){
	long long nSwap;
	int idx = 0;
	
	int middle, left, right;
	if(len <= 1) return 0;
	
	int b[len];
	middle = len >> 1;
	nSwap = mergeSort(a, middle);
	nSwap += mergeSort(&a[middle], len - middle);
	left = 0;
	right = middle;
	while( (left < middle) && (right < len)){
		if(a[left] <= a[right]){			
			b[idx++] = a[left++];
		}
		else{
			nSwap += middle - left;
			b[idx++] = a[right++];
		}
	}
	while(left < middle){
		b[idx++] = a[left++];
	}
	while(right < len){
		b[idx++] = a[right++];
	}
	memcpy(a, b, sizeof(int)*len);
	return nSwap;
}

int main(){
	int len, i, middle;
	int a[MAX];
	long long ans;
	
	while(1 == scanf("%d", &len)){
		if(len == 0) return 0;

		if(DEBUG){
			printf("array len = %d\n", len);
		}				
		for(i=0; i<len; i++){
			scanf("%d",&a[i]);
		}
		middle = len >> 1;
		ans = mergeSort(a, len);
		printf("%lld\n",ans);
	}
	return 0;
}

