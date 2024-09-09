/*AC*/
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define NCAMPSITE 602
#define YES 1
#define NO 0
#define DEBUG 0

unsigned long dist[NCAMPSITE];
unsigned long nNight, nCamp;

unsigned long ifPossible(unsigned long pivot){
	unsigned long dayCount = 0;
	unsigned long sum;
	unsigned long i;
	
	sum = dist[0];

	if(pivot < dist[0]){
		return NO;
	} 	
	
	for(i = 1; i<=nCamp; i++){
		if(pivot < dist[i]){
			return NO;
		}
		if(sum + dist[i] > pivot){
			dayCount++;
			sum = dist[i];
		}
		else {
			sum += dist[i];
		}
	}
	if(DEBUG){
		printf("pivot: %ld dayCount = %ld, night=%ld\n",pivot, dayCount,nNight);
	}
	if(dayCount <= nNight) return YES;
	else return NO;
}

int main(){
	unsigned long i, ans, total, tmpAns;
	unsigned long left, right;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;
	
	while( 2 == fscanf(fp, "%ld %ld",&nCamp, &nNight)){
		total = 0;
		for(i=0;i<=nCamp;i++){
			fscanf(fp, "%ld", &dist[i]);
			total += dist[i];
		}
		ans = total - 1;
		left = 0;
		right = total;
		while(left <= right){
			tmpAns = (left + right) >> 1;
			if(ifPossible(tmpAns) == YES){
				right = tmpAns - 1;
				ans = tmpAns;
			}
			else {
				left = tmpAns + 1;
			}
		}
		printf("%lu\n",ans);
		
	}
	return 0;
}
