#include <stdio.h>
#define NCAMPSITE 602

int dist[NCAMPSITE];
int nNight, nCamp;

int ifPossible(int pivot){
	int dayCount = 0;
	int sum;
	int i;
	sum = dist[0];
	for(i = 1; i<=nCamp; i++){
		if(sum + dist[i] > pivot){
			dayCount++;
			sum = dist[i];
		}
		else {
			sum += dist[i];
		}
	}
	return nNight - dayCount;
}

int main(){
	int i, ans, total, tmpAns;
	int left, right;
	int max;
	while( 2 == scanf("%d %d",&nCamp, &nNight)){
		total = 0;
		max = -1;
		for(i=0;i<=nCamp;i++){
			scanf("%d", &dist[i]);
			total += dist[i];
			if(dist[i] > max){
				max = dist[i];
			}
		}
		ans = total - 1;
		left = max;
		right = total;
		while(left <= right){
			tmpAns = (left + right) >> 1;
			if(ifPossible(tmpAns) >= 0){
				right = tmpAns - 1;
				ans = tmpAns;
			}
			else {
				left = tmpAns + 1;
			}
		}
		printf("%d\n",ans);
		
	}
	return 0;
}
