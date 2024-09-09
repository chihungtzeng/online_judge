#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#define MAXCITY 101
#define INTMAX 2000000000
#define DEBUG 1

struct City{
	short sn;
	char name[32];
	char hasMaternity;
	char removeMaternity;
	int x, y, nPeople;
};

struct City *city;
short nCity, nClose, nInitMaternity;
long dist[MAXCITY][MAXCITY];
long cost[MAXCITY][MAXCITY];

void setCity(struct City *c, char *name, int np, int x, int y){
	assert((name != NULL) && (c != NULL));
	c->sn = -1;
	strcpy(c->name, name);
	c->nPeople = np;
	c->x = x;
	c->y = y;
	c->hasMaternity = 0;
	c->removeMaternity = 0;
}

int gcd(int a, int b){
	if(0 == b) return a;
	else return gcd(b, a%b);
}

void printCityInfo(struct City *c){
	printf("City %hd(%s) location:(%d, %d) ", c->sn, c->name, c->x, c->y);
	printf("population: %d, Maternity Service: %hd\n", c->nPeople, c->hasMaternity);
}

int compareCity(const void *a, const void *b){
	struct City *s, *t;
	s = (struct City *)a;
	t = (struct City *)b;
	return strcmp(s->name, t->name);
}

void computCostBetweenCity(){
	short i, j;
	for(i=0; i<nCity; i++){
		for(j=i+1; j<nCity; j++){
			dist[i][j] = sqrt((city[i].x - city[j].x)*(city[i].x - city[j].x) + (city[i].y - city[j].y)*(city[i].y - city[j].y));
			dist[j][i] = dist[i][j];
		}
	}
	for(i=0; i<nCity; i++){
		for(j=0; j<nCity; j++){
			cost[i][j] = city[i].nPeople * dist[i][j];
		}
	}
	if(DEBUG){
		for(i=0; i<nCity; i++){
			for(j=0; j<nCity; j++){
				printf("%5ld ", cost[i][j]);
			}
			printf("\n");
		}
	}
}

long totalMaternityCost(struct City *city){
	short i, j;
	long result = 0;
	long min;
	
	for(i=0; i<nCity; i++){
		if(city[i].hasMaternity == 0){
			min = INTMAX;
			for(j=0; j<nCity; j++){
				if(cost[i][j] < min){
					min = cost[i][j];
				}
			}
			result += min;
		}
	}
	return result;
}

long findWhichOneClose(struct City *city, short nClose){
	long min, afterClose;
	short i, j, closeIndex;
	struct City *try, *bestAnswer;

	if(nClose == 0) return totalMaternityCost(city);
	
	
	try = (struct City *) malloc(sizeof(struct City)*nCity);
	bestAnswer = (struct City *) malloc(sizeof(struct City)*nCity);
	
	
	
	/*greedy approach: if city i has maternity service, 
	then see what will happen if the service is down*/
	min = INTMAX;
	for(j=0; j<nCity; j++){
		if(city[j].hasMaternity == 0){
			continue;
		}
		memcpy(try, city, sizeof(struct City)*nCity);
		try[j].hasMaternity = 0;
		afterClose = findWhichOneClose(try, nClose - 1);
		if(afterClose < min){
			min = afterClose;
			closeIndex = j;
			memcpy(bestAnswer, try, sizeof(struct City)*nCity);
		}
		/*city[j].hasMaternity = 1; restore the orginal state*/
	}
	memcpy(city, bestAnswer, sizeof(struct City)*nCity);
	city[closeIndex].hasMaternity = 0;
	city[closeIndex].removeMaternity = 1;
	return min;
}


int main(){
	short i, j;
	char cityName[32];
	char firstCase = 1;
	int x, y, np;
	struct City *matchCity, queryCity;
	
	city = (struct City *) malloc(sizeof(struct City)*MAXCITY);
	
	while(1 == scanf("%hd", &nCity)){
		for(i=0; i<nCity; i++){
			scanf("%s %d %d %d", cityName, &np, &x, &y);
			setCity(city + i, cityName, np, x, y);
		}
		qsort(city, nCity, sizeof(struct City), compareCity);
		
		for(i=0; i<nCity; i++){
			city[i].sn = i;
		}
		if(nCity >= 2){
			int g;
			g = gcd(city[0].nPeople, city[1].nPeople);
			for(i=2; i<nCity; i++){
				g = gcd(g, city[i].nPeople);
			}
			for(i=0; i<nCity; i++){
				city[i].nPeople = city[i].nPeople/g;
			}
		}		
		
		scanf("%hd", &nInitMaternity);
		for(i=0; i<nInitMaternity; i++){
			scanf("%s", cityName);
			setCity(&queryCity, cityName, 0, 0, 0);
			matchCity = (struct City *) bsearch(&queryCity, city, nCity, sizeof(struct City), compareCity);
			if(matchCity == NULL){
				printf("No match with city name %s\n", cityName);
			}
			else{
				
				matchCity->hasMaternity = 1;
			}
		}
		
		scanf("%hd", &nClose);
		if(DEBUG){
			for(i=0; i<nCity; i++){
				printCityInfo(city + i);
			}
			printf("%hd services to be close\n",nClose);
		}
		memset(dist, 0, sizeof(int)*MAXCITY*MAXCITY);
		computCostBetweenCity();
		findWhichOneClose(city, nClose);
		if(firstCase){
			firstCase = 0;
		}
		else{
			printf("\n");
		}
		for(i=0; i<nCity; i++){
			if(city[i].removeMaternity == 1){
				printf("%s\n",city[i].name);
			}
		}
	}
	free(city);
	return 0;
}