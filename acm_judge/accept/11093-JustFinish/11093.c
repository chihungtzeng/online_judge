#include <stdio.h>
#define MAX 100001
#define DEBUG 0

int nStation;
int petrol[MAX];
int dist[MAX];

int solve(){
	int gas;
	int i, j;
	char possible;
	
	for(i=0; i<nStation; i++){

		gas = petrol[i] - dist[i];
		possible = (gas < 0)? 0 : 1;		
		for(j = i + 1; (j != i) && possible; j = (j+1) % nStation){
			gas = gas + petrol[j] - dist[j];
			if(gas < 0){
				possible = 0;
			} 
		}
		if(possible) return i;
	}
	return MAX;
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