#include <stdio.h>
#include <string.h>
#define FIRST 1
#define SECOND 2
#define P2B 0
#define B2A 1
#define POLITICIAN 0
#define BUSINESSMEN 1
#define ARTIST 2
#define YOUNG 3
#define TOURIST 4
#define REGULAR 5
#define WAGON_FIRST_CAPACITY 48
#define WAGON_SECOND_CAPACITY 64
#define VERBOSE 0

int nPassenger[6][2];
int nWagon[3][2];
int nEmptySeat[3][2];

int max(int a, int b){
	if(a > b) return a;
	else return b;
}

int myceil(int n, int m){
	/*return ceil(n/m)*/
	int result;
	result = n / m;
	if(n % m != 0){
		result++;
	}
	return result;
}

void decideWagon(){
	int i;
	memset(nWagon, 0, sizeof(int)*6);
	memset(nEmptySeat, 0, sizeof(int)*6);
	
	for(i=0; i<=1; i++){
		nWagon[FIRST][i] = myceil( nPassenger[POLITICIAN][i], WAGON_FIRST_CAPACITY);
		nWagon[FIRST][i] += myceil( nPassenger[BUSINESSMEN][i], WAGON_FIRST_CAPACITY);
		nWagon[SECOND][i] = myceil( nPassenger[ARTIST][i],  WAGON_SECOND_CAPACITY);
		nWagon[SECOND][i] += myceil( nPassenger[YOUNG][i],  WAGON_SECOND_CAPACITY);
 
		nEmptySeat[SECOND][i] = 
			nWagon[SECOND][i] * WAGON_SECOND_CAPACITY 
			- nPassenger[ARTIST][i] - nPassenger[YOUNG][i];
		if(nEmptySeat[SECOND][i] >= nPassenger[TOURIST][i]){
			nEmptySeat[SECOND][i] -= nPassenger[TOURIST][i];
		} 
		else{
			int nNewWagon;
			nNewWagon = myceil(nPassenger[TOURIST][i] - nEmptySeat[SECOND][i],  WAGON_SECOND_CAPACITY);
			nWagon[SECOND][i] += nNewWagon;
		}
		if(VERBOSE){
			printf("%i sec, empty seats: first-class:%d second-class:%d\n", i, nEmptySeat[FIRST][i], nEmptySeat[SECOND][i]);
		}
	}

						

	/*Now for regular passengers*/
	int nTotalEmptySeat, nRegularRemains, nNewSecondWagon;
	for(i=0; i<=1; i++){
		nEmptySeat[FIRST][i] = 
			max(nWagon[FIRST][P2B], nWagon[FIRST][B2A]) * WAGON_FIRST_CAPACITY 
			- nPassenger[POLITICIAN][i] - nPassenger[BUSINESSMEN][i];
		nEmptySeat[SECOND][i] = 
			max(nWagon[SECOND][P2B], nWagon[SECOND][B2A]) * WAGON_SECOND_CAPACITY 
			- nPassenger[ARTIST][i] - nPassenger[YOUNG][i] - nPassenger[TOURIST][i];
		nTotalEmptySeat = nEmptySeat[FIRST][i] + nEmptySeat[SECOND][i];
		nPassenger[REGULAR][i] = nPassenger[REGULAR][i] - nTotalEmptySeat;
	}
	
	nRegularRemains = max(nPassenger[REGULAR][P2B], nPassenger[REGULAR][B2A]);
	if(nRegularRemains > 0){
		nNewSecondWagon = myceil(nRegularRemains, WAGON_SECOND_CAPACITY);
		nWagon[SECOND][P2B] += nNewSecondWagon;
		nWagon[SECOND][B2A] += nNewSecondWagon;
	}
	
}

int main(){
	char first = 1; 
	int i, j, nPeople;
	
	while(1 == scanf("%d", &nPassenger[0][0])){
		if(first){
			first = 0;
		}
		else{
			printf("\n");
		}
		nPassenger[0][1] = nPassenger[0][0];
		for(i=1; i<6; i++){
			scanf("%d", &nPassenger[i][0]);
			nPassenger[i][1] = nPassenger[i][0];
		}
		for(i=0; i<2; i++){
			for(j=0; j<6; j++){
				scanf("%d",&nPeople);
				nPassenger[j][i] += nPeople; 
			}
		}
		
		if(VERBOSE){
			for(i=0; i<2; i++){
				for(j=0;j<6;j++){
					printf("%d ", nPassenger[j][i]);
				}
				printf("\n");
			}
			
		}
		decideWagon();
		if(VERBOSE){
			printf("1st Wagon: %d (P to B), %d (B to A)\n", nWagon[FIRST][P2B], nWagon[FIRST][B2A]);
			printf("2nd Wagon: %d (P to B), %d (B to A)\n", nWagon[SECOND][P2B], nWagon[SECOND][B2A]);
		}
		printf("%d\n", max(nWagon[FIRST][P2B], nWagon[FIRST][B2A]) );
		printf("%d\n", max(nWagon[SECOND][P2B], nWagon[SECOND][B2A]) );
	}
	return 0;	
}
 
