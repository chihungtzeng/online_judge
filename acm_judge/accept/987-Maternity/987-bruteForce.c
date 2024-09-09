#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#define MAXCITY 128
#define INTMAX 10000000000000000
#define DEBUG 0
#define OPEN 1
#define CLOSE 0
#define VERBOSE 0

struct City{
	short sn;
	char name[32];
	char hasMaternity;
	int x, y;
	long long nPeople;
};

struct City *city;
short nCity, nClose, nInitMaternity, nOpen;
long long bestAns;

long long gcd(long long a, long long b){
	if(0 == b) return a;
	else return gcd(b, a % b);
}

long long cost[MAXCITY][MAXCITY];
short maternityCityIndex[MAXCITY];
short ans[MAXCITY];
FILE *outfp;

void setCity(struct City *c, char *name, long long np, int x, int y){
	assert((name != NULL) && (c != NULL));
	c->sn = -1;
	strcpy(c->name, name);
	c->nPeople = np;
	c->x = x;
	c->y = y;
	c->hasMaternity = 0;
}


void printCityInfo(struct City *c){
	printf("City %hd(%s) location:(%d, %d) ", c->sn, c->name, c->x, c->y);
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
	double dist;
	double tmp;
	double maxDist = 0;
	short dest;
	short i, j;
	for(i=0; i<nCity; i++){
		for(j=0; j<nInitMaternity; j++){
			dest = maternityCityIndex[j];
			dist = sqrt((city[i].x - city[dest].x)*(city[i].x - city[dest].x) + (city[i].y - city[dest].y)*(city[i].y - city[dest].y));
			cost[i][j] = dist * city[i].nPeople;
		}
	}
	 
	
	if(DEBUG){
		for(i=0; i<nCity; i++){
			printf("city %hd", i);
			for(j=0; j<nInitMaternity; j++){
				printf("%10lld ", cost[i][j]);
			}
			printf("\n");
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
		if(dest < 0){
			if(DEBUG){
				printf("No closest city!\n");
			}
			return 0;
		}
		else return dest;
	}
} 




long long findThoseClose(short pos, short closeListIndex, short closeList[], const short upParent[], long long curCost){
	/*check city "pos"  */
	short closeListBak[MAXCITY];
	short parent[nCity];
	short i, j, np;
	long long min = INTMAX, result;
	long long extraCost = 0;
/*	
	if(DEBUG){
		printf("------------------------\n");
		printf("begin func call: pos=%hd closeListIndex=%hd curCost = %lld\n", pos, closeListIndex, curCost);
		printf("closeList=");
		for(i=0; i<closeListIndex; i++){
			printf("%hd ", closeList[i]);
		}
		printf("\n parent list:");
		for(i=0; i<nCity; i++){
			printf("%hd ", upParent[i]);
		}
		printf("\n");
	}
*/
	
	
	if(closeListIndex == nClose) {
		if(VERBOSE){
			for(i=0; i<nClose; i++){
				fprintf(outfp, "%hd ", closeList[i]);
			}
			fprintf(outfp, "\n");
		}
		return curCost;
	}
	if(nInitMaternity - pos < nClose - closeListIndex){
		return INTMAX;
	} 
	if(pos >= nInitMaternity) return INTMAX;
	
	memcpy(closeListBak, closeList, sizeof(short)*nClose);


	if(nInitMaternity - pos == nClose - closeListIndex) {
		for(i=pos; i<nInitMaternity; i++){
			closeList[closeListIndex++] = i;
		}
		result = 0;
		qsort(closeList, nClose, sizeof(short), compareShort);
		for(j=0; j<nCity; j++){
			parent[j] = cloestMaternityCity(j, closeListIndex, closeList);
			result += cost[j][parent[j]];
		}
		if(result < bestAns){
			bestAns = result;
			memcpy(ans, closeList, sizeof(short)*nClose);
			if(DEBUG){
				printf("***Better Ans %lld **** close list:", bestAns);
				for(i=0; i<nClose; i++){
						printf("%hd ", closeList[i]);
				}
				printf("\n");
			}
		}
		if(VERBOSE){
			for(i=0; i<nClose; i++){
				fprintf(outfp, "%hd ", closeList[i]);
			}
			fprintf(outfp, "\n");
		}
		return result;
	}

	
	/*recursively find ans*/
	closeList[closeListIndex++] = pos; /*maternity city 0 stops the service*/
	qsort(closeList, closeListIndex, sizeof(short), compareShort);
	memcpy(parent, upParent, sizeof(short)*nCity);
	for(i=0; i<nCity; i++){
		if(parent[i] == pos){
			extraCost -= cost[i][parent[i]];
			parent[i] = cloestMaternityCity(i, closeListIndex, closeList);
			extraCost += cost[i][parent[i]]; 
		} 
	}
	/*
	if(curCost + extraCost > bestAns){
		
	}
	else {
	*/
		result = findThoseClose(pos + 1, closeListIndex, closeList, parent, curCost + extraCost);
		
		if(result < min){
			min = result;	
		}
		if(min < bestAns){
			memcpy(ans, closeList, sizeof(short)*nCity);
			bestAns = min;
			if(DEBUG){
				printf("***Better Ans %lld **** close list:", bestAns);
				for(i=0; i<nClose; i++){
						printf("%hd ", closeList[i]);
				}
				printf("\n");
			}
		}
	/*}*/
	closeListIndex--;
	memcpy(closeList, closeListBak, sizeof(short)*nClose);
	result = findThoseClose(pos + 1, closeListIndex, closeList, upParent, curCost);
	
	if(result < min){
		min = result;
	}
	if(min < bestAns){
		memcpy(ans, closeList, sizeof(short)*nClose);
		bestAns = min;
		if(DEBUG){
			printf("***Better Ans %lld **** close list:", result);
			for(i=0; i<nClose; i++){
					printf("%hd ", closeList[i]);
			}
			printf("\n");
		}
	}
	
	
	
	
	if(DEBUG){
		if(min == INTMAX){
			printf("Find no answer Q_Q pos=%hd closeListIndex=%hd:\n", pos, closeListIndex);
			for(i=0; i<closeListIndex; i++){
				printf("%hd ",closeList[i]);
			}
			printf("\n");
		}
		printf("pos = %d returns min = %lld\n", pos, min);	
	}
	
	
	return min;
}



int main(){
	short i, j;
	char cityName[32];
	char firstCase = 1, type;
	short closeList[MAXCITY], openList[MAXCITY];
	short parent[MAXCITY]; /*Current closest maternity city*/
	int x, y;
	long long np;
	struct City *matchCity, queryCity;
	long long curCost;
	FILE *fp;
	
	
	outfp = (VERBOSE)? fopen("/mnt/ramdisk/shit.txt", "w") : stdout;
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
		
		
		for(i=0; i<nCity; i++){
			city[i].sn = i;
		}
		np = city[0].nPeople; /*find the gcd of population*/
		for(i=1; i<nCity; i++){
			np = gcd(np, city[i].nPeople);
		}
		if(DEBUG){
			printf("gcd of population is %lld\n",np);
		}
		for(i=0; i<nCity; i++){
			city[i].nPeople = city[i].nPeople / np;
		}
		
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
		/*
		nOpen = nInitMaternity - nClose;
		type = (nClose < nOpen)? CLOSE : OPEN;
		*/
			bestAns = INTMAX;
			curCost = 0; 
			for(i=0; i<nCity; i++){
				/*Initially, every maternity service is on*/
				parent[i] = cloestMaternityCity(i, 0, NULL);
				curCost += cost[i][parent[i]];
			}
			memset(closeList, 0, sizeof(short)*nCity);
			curCost = findThoseClose(0, 0, closeList, parent, curCost);
			if(DEBUG){
				printf("final cost: %lld\n",bestAns);
			}
			/*start output*/
			
			qsort(ans, nClose, sizeof(short), compareShort);
			for(i=0; i<nClose; i++){
				j = maternityCityIndex[ans[i]];
				printf("%s\n",city[j].name);
			}
			
	}
	free(city);
	return 0;
}