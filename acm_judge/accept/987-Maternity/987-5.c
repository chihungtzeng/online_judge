/*AC 0.196s*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#define MAXCITY 128
#define INTMAX 10000000000000000
#define DEBUG 0
#define VERBOSE 0

struct City{
	char name[32];
	char hasMaternity;
	int x, y;
	long long nPeople;
};

struct City *city;
short nCity, nClose, nInitMaternity, nOpen;
long long bestAns;


long long cost[MAXCITY][MAXCITY];
short maternityCityIndex[MAXCITY];
short ans[MAXCITY];


void setCity(struct City *c, char *name, long long np, int x, int y){
	assert((name != NULL) && (c != NULL));
	strcpy(c->name, name);
	c->nPeople = np;
	c->x = x;
	c->y = y;
	c->hasMaternity = 0;
}


void printCityInfo(struct City *c){
	printf("City %s: location:(%d, %d) ", c->name, c->x, c->y);
	printf("population: %lld, Maternity Service: %hd\n", c->nPeople, c->hasMaternity);
}

int compareCity(const void *a, const void *b){
	struct City *s, *t;
	s = (struct City *)a;
	t = (struct City *)b;
	return strcmp(s->name, t->name);
}

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b; 
}

void computCostFunction(){
	int dist;
	short dest;
	short i, j;
	for(i=0; i<nCity; i++){
		for(j=0; j<nInitMaternity; j++){
			dest = maternityCityIndex[j];
			cost[i][j] = city[i].nPeople * (abs(city[i].x - city[dest].x) + abs(city[i].y - city[dest].y));
		}
	}
}

short cloestMaternityCity(short src, short nShut, short shutList[]){
	short dest = -1, i;
	long long min = INTMAX;
	if(nShut == 0){
		for(i=0; i<nInitMaternity; i++){
			if(cost[src][i] < min){
				min = cost[src][i];
				dest = i;
			}
		}
		return dest;
	}
	else{
		for(i=0; i<nInitMaternity; i++){
			if( (cost[src][i] < min) && (NULL == bsearch(&i, shutList, nShut, sizeof(short), compareShort))){
				min = cost[src][i];
				dest = i;
			} 
		}
		return dest;
	}
} 




long long findThoseClose(short pos, short closeListIndex, short closeList[], const short upParent[], long long curCost){
	/*check city "pos"  */
	short closeListBak[MAXCITY];
	short parent[nCity];
	short i, j, np;
	long long min = INTMAX, result;
	long long extraCost;

	
	
	if(closeListIndex == nClose) {
		if(curCost < bestAns){
			bestAns = curCost;
			memcpy(ans, closeList, sizeof(short)*nClose);
		}
		return curCost;
	}
	if(nInitMaternity - pos < nClose - closeListIndex){
		return INTMAX;
	} 
	if(pos >= nInitMaternity) return INTMAX;
	
	/*recursively find ans*/
	closeList[closeListIndex++] = pos; /*maternity city 0 stops the service*/
	memcpy(parent, upParent, sizeof(short)*nCity);
	extraCost = curCost;
	for(i=0; i<nCity; i++){
		if(parent[i] == pos){
			extraCost -= cost[i][parent[i]];
			parent[i] = cloestMaternityCity(i, closeListIndex, closeList);
			extraCost += cost[i][parent[i]]; 
		} 
	}
	
	if(extraCost >= bestAns){
	}
	else {
		findThoseClose(pos + 1, closeListIndex, closeList, parent, extraCost);
	}
	closeListIndex--;
	result = findThoseClose(pos + 1, closeListIndex, closeList, upParent, curCost);
	return min;
}



int main(){
	short i, j;
	char cityName[32];
	char firstCase = 1;
	short closeList[MAXCITY], openList[MAXCITY];
	short parent[MAXCITY]; /*Current closest maternity city*/
	int x, y;
	long long np;
	struct City *matchCity, queryCity;
	long long curCost;
	FILE *fp;
	
	
	
	fp = (DEBUG)? fopen("in2.txt","r"):stdin;
	
	city = (struct City *) malloc(sizeof(struct City)*MAXCITY);
	
	while(1 == fscanf(fp, "%hd", &nCity)){

		if(firstCase){
			firstCase = 0;
		}
		else{
			printf("\n");
		}
		
		for(i=0; i<nCity; i++){
			fscanf(fp, "%s %lld %d %d", cityName, &np, &x, &y);
			setCity(city + i, cityName, np, x, y);
		}
		qsort(city, nCity, sizeof(struct City), compareCity);
		
		
		
		
		fscanf(fp, "%hd", &nInitMaternity);
		for(i=0; i<nInitMaternity; i++){
			fscanf(fp,"%s", cityName);
			setCity(&queryCity, cityName, 0, 0, 0);
			matchCity = (struct City *) bsearch(&queryCity, city, nCity, sizeof(struct City), compareCity);
			if((matchCity == NULL) && DEBUG){
				printf("No match with city name %s\n", cityName);
			}
			else{		
				matchCity->hasMaternity = 1;
			}
		}
		
		fscanf(fp, "%hd", &nClose);
		if(DEBUG){
			for(i=0; i<nCity; i++){
				printCityInfo(city + i);
			}
			printf("%hd services to be close\n",nClose);
		}
		/*prepare data, we only calculate the cost to maternity cities*/
		j=0;
		for(i=0; i<nCity; i++){
			if(city[i].hasMaternity){
				maternityCityIndex[j++] = i;
			}
		}
		computCostFunction();
		
		bestAns = INTMAX;
		curCost = 0; 
		for(i=0; i<nCity; i++){
			/*Initially, every maternity service is on*/
			parent[i] = cloestMaternityCity(i, 0, NULL);
			curCost += cost[i][parent[i]];
		}
		memset(closeList, 0, sizeof(short)*nCity);
		findThoseClose(0, 0, closeList, parent, curCost);
		if(DEBUG){
			printf("final cost: %lld\n",bestAns);
		}
		/*start output*/
		
		/*qsort(ans, nClose, sizeof(short), compareShort);*/
		for(i=0; i<nClose; i++){
			j = maternityCityIndex[ans[i]];
			printf("%s\n",city[j].name);
		}
		
	}
	free(city);
	return 0;
}