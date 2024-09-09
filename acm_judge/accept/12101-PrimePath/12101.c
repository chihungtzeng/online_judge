#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
#define MAX_PRIME_STRUCT 1061
#define MAX_PRIME_STRUCT_NEIGHBOR 14
#define INF 0x7fff
#define DEBUG 0

struct Prime{
	short num;
	short nNeighbor;
	short neighbor[MAX_PRIME_STRUCT_NEIGHBOR];
	short dist;
};

struct Prime *tPrime;
short nPrime;

int isNeighbor(short small, short big){
	/*if a and b only diff from 1 digit, return 1, else return 0*/
	int nSameDigit = 0;
	
	while(small > 0){
		if(small % 10 == big % 10){
			nSameDigit++;
		}
		small = small / 10;
		big = big / 10;
	}	
	if(3 == nSameDigit) {
		return 1;
	}
	else return 0;
}

void buildPrimeTable(){
	char isPrime[MAX];
	short i, j;
	memset(isPrime, 1, MAX);
	for(i=2; i<MAX; i++){
		if(isPrime[i]){
			for(j=i+i; j<MAX; j+=i){
				isPrime[j] = 0;
			}
		}
	}
	nPrime = 0;
	for(i=1001; i<MAX; i++){
		if(isPrime[i]){
			tPrime[nPrime].num = i;
			tPrime[nPrime].nNeighbor = 0;
			nPrime++; 
		}
	}
	for(i=0; i<nPrime; i++){
		for(j=0; j<i; j++){
			if( isNeighbor(tPrime[j].num, tPrime[i].num)){
				tPrime[i].neighbor[tPrime[i].nNeighbor] = j;
				tPrime[i].nNeighbor += 1;
				tPrime[j].neighbor[tPrime[j].nNeighbor] = i;
				tPrime[j].nNeighbor += 1;
			} 
		}
	}
	#if DEBUG
	int max = 0;
	for(i=0; i<nPrime; i++){
		printf("%d ", tPrime[i].num);
		if(tPrime[i].nNeighbor > max){
			max = tPrime[i].nNeighbor;
		}
	}
	printf("\nnPrime=%d\n", nPrime);
	printf("max=%d\n", max);
	#endif
}

short myBsearch(short target){
	short left = 0, right = nPrime - 1, middle;
	while(left <= right){
		middle = (left + right) >> 1;
		if(tPrime[middle].num == target) return middle;
		else if (tPrime[middle].num < target) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right) >> 1;
}

short BFS(short src, short dest){
	short queue[MAX_PRIME_STRUCT];
	short head = 0, tail = 1;
	short cur, target, i;
	short srcIndex, destIndex;
	
	srcIndex = myBsearch(src);
	destIndex = myBsearch(dest);
	#if DEBUG
	printf("tPrime[%hd].num = %hd\n", srcIndex, src);
	printf("tPrime[%hd].num = %hd\n", destIndex, dest);
	#endif
	for(cur = 0; cur < nPrime; cur++){
		tPrime[cur].dist = INF;
	}
	tPrime[srcIndex].dist = 0;
	queue[0] = srcIndex;
	
	while(head < tail){
		cur = queue[head++];
		for(i=0; i<tPrime[cur].nNeighbor; i++){
			target = tPrime[cur].neighbor[i];
			if(tPrime[cur].dist + 1 < tPrime[target].dist){
				tPrime[target].dist = tPrime[cur].dist + 1;
				queue[tail++] = target;
			}
			if(target == destIndex){
				return tPrime[target].dist;
			}
		}
	}
	return tPrime[destIndex].dist;
}

int main(){
	short nTest, src, dest, dist;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	fscanf(fp, "%hd", &nTest);
	tPrime = (struct Prime *) malloc(sizeof(struct Prime)*MAX_PRIME_STRUCT);
	buildPrimeTable();
	
	
	while(nTest--){
		fscanf(fp, "%hd %hd", &src, &dest);
		dist = BFS(src, dest);
		if(dist == INF){
			printf("Impossible\n");
		} else {
			printf("%hd\n", dist);
		}
	}
	
	free(tPrime);
	return 0;
}