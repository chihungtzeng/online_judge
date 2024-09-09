#include <stdio.h>
#define MAX 50001

int height[MAX];
int nFemale;

int mybsearch(int target){
	int left, right, middle;
	left = 0;
	right = nFemale - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(height[middle] == target) return middle;
		else if (height[middle] < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right) >> 1;
}

int main(){
	
	int query[25000], nQuery;
	int i, left, right, match;
	int target;
	scanf("%d",&nFemale);
	for(i=0; i<nFemale; i++){
		scanf("%d", height + i);
	}
	scanf("%d",&nQuery);
	for(i=0; i<nQuery; i++){
		scanf("%d", query + i);
	}
	for(i=0; i<nQuery; i++){
		target = query[i];
		left = mybsearch(target);
		right = left;
		/*printf("left = %d height[left]=%d\n",left, height[left]);*/
		while( (left >= 0) && (height[left] >= target)){
			left--;
		}
		while( (right < nFemale) && (height[right] <= target)){
			right++;
		}
		if(left < 0){
			printf("X");
		}
		else{
			printf("%d", height[left]);
		}
		if(right >= nFemale){
			printf(" X\n");
		}
		else{
			printf(" %d\n",height[right]);
		}
	}
	return 0;
}