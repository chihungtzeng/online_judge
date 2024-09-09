#include <stdio.h>
#define MAX 100001
#define DEBUG 0

int nStation;
int petrol[MAX];
int dist[MAX];

int findCheckPoint(int *oilRemain) {
	int i, checkPoint = -1;
	int oil = petrol[0];
	for(i=1; i<nStation; i++){
		if(oil >= dist[i-1]){
			oil = oil - dist[i-1] + petrol[i];
		}
		else{
			checkPoint = i;
			oil = petrol[i];
		}
	}
	*oilRemain = oil;
	return checkPoint;
}

int solve() {
	int checkPoint, oil;
	int i, pre;
	checkPoint = findCheckPoint(&oil);
	if(checkPoint < 0) return MAX;
	pre = dist[nStation - 1];
	for(i=0; i<checkPoint; i++){
		if(oil >= pre){
			oil = oil - pre + petrol[i];
			pre = dist[i];
		}
		else {
			return MAX;
		}
	}
	oil = oil - pre;
	
	return (oil >= 0)? checkPoint : MAX;
}

int main(){
	char k = 1;
	char nTest;
	int i, station;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	fscanf(fp, "%hhd", &nTest);
	while(nTest > 0){
		nTest--;
		fscanf(fp, "%d", &nStation);
		for(i=0; i<nStation; i++){
			fscanf(fp, "%d", petrol + i);
		} 
		for(i=0; i<nStation; i++){
			fscanf(fp, "%d", dist + i);
		}
		station = solve();
		if(station < nStation){
			printf("Case %hhd: Possible from station %d\n", k, station + 1);
		}
		else{
			printf("Case %hhd: Not possible\n", k);
		}
		k++;
	}
	return 0;
}