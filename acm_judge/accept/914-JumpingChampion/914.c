#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000000
#define DEBUG 0



int *primelist;
int nPrime;

void initPrimeList(){
	int j;
	short isPrime;
	int sq;
	int start;
	primelist[0] = 2;
	primelist[1] = 3;	
	nPrime = 2;
	start = 5;
	while(start <= 999997){
		if(start % 3 == 0){
			start += 2;
			continue;
		}
		isPrime = 1;
		sq = (int) sqrt(start);
		for(j=0; (primelist[j] <= sq) && (isPrime == 1);j++){
			if(start % primelist[j] == 0){
				isPrime = 0;
			}
		}
		if(isPrime){
			primelist[nPrime++] = start;
		}
		start += 2;
	}
}

int binsearch(int target){
	int left, right, middle;
	left = 0;
	right = nPrime - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(primelist[middle] == target){
			return middle;
		}
		else if (primelist[middle] < target){
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return (left + right) >> 1;
}

int compareInt(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

struct hashele{
	int value;
	int freq;
};

compareHashEle(const void *a, const void *b){
	struct hashele x, y;
	x = *(struct hashele *)a;
	y = *(struct hashele *)b;
	return y.freq - x.freq;
}

int main(){
	int lb, ub, left, right;
	int nTest, i;
	int *interval, nInt;
	int count, curInt, ans, ansCount, nHashEle;
	struct hashele *hashtable;
	primelist = (int *) malloc(sizeof(int)*MAX);
	initPrimeList();	
	interval = (int *) malloc(sizeof(int)*nPrime);
	hashtable = (struct hashele *) malloc(sizeof(struct hashele)*nPrime);


	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d",&lb, &ub);
		left = binsearch(lb);
		right = binsearch(ub);


		if(DEBUG){
			printf("lb:%d ub:%d left:%d right:%d\n",lb,ub,left,right);
		}
		
		if( (left < 0) || (primelist[left] < lb)) { left++; }
		if(right - left  <= 0) {
			printf("No jumping champion\n");
			continue;
		}
		if(right - left == 1){
			printf("The jumping champion is %d\n", primelist[right] - primelist[left]);
			continue;
		}

		nInt = 0;
		for(i=left; i<right; i++){
			interval[nInt++] = primelist[i+1] - primelist[i];
		}
		qsort(interval, nInt, sizeof(int), compareInt);
		if(DEBUG){
			for(i=left;i<=right;i++){
				printf("%d ",primelist[i]);
			}
			printf("\n");
			for(i=0;i<nInt;i++){
				printf("%d ",interval[i]);
			}
			printf("\n");
		}
		count = 1;
		curInt = interval[0];
		nHashEle = 0;
		for(i=1; i<nInt; i++){
			if(curInt == interval[i]){
				count++;
			}
			else {
				hashtable[nHashEle].value = curInt;
				hashtable[nHashEle].freq = count;
				curInt = interval[i];
				nHashEle++;
				count = 1;
			}
		}
				hashtable[nHashEle].value = curInt;
				hashtable[nHashEle].freq = count;
				nHashEle++;

		qsort(hashtable, nHashEle, sizeof(struct hashele), compareHashEle);
		if(hashtable[0].freq == hashtable[1].freq){
			printf("No jumping champion\n");
		}
		else{
			printf("The jumping champion is %d\n", hashtable[0].value);
		}
		if(DEBUG){
			for(i=0; i<nHashEle; i++){
				printf("value:%d freq:%d\n",hashtable[i].value, hashtable[i].freq);
			}
		}
	}
	
	free(interval);
	free(hashtable);
	return 0;
}
