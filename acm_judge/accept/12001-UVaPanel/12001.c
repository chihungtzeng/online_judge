#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM_COUNTRY 51
#define MAX_NUM_PEOPLE 301
#define DEBUG 0

int choose3[MAX_NUM_PEOPLE];
int choose4[MAX_NUM_PEOPLE];
int from3[MAX_NUM_COUNTRY][MAX_NUM_COUNTRY][MAX_NUM_COUNTRY];
short nPeople, nCountry;
short country[MAX_NUM_COUNTRY];

int compareShort(const void *a, const void *b){
	return *(short *)b - *(short *)a;
}

void buildChoose3Table(){
	int i;
	for(i=0; i<3; i++){
		choose3[i] = 0;
		choose4[i] = 0;
	}
	choose3[3] = 1;
	choose4[3] = 0;
	choose4[4] = 1;
	for(i=4; i < MAX_NUM_PEOPLE; ++i){
		choose3[i] = (choose3[i-1]*i)/(i-3); 
	}
	for(i=5; i < MAX_NUM_PEOPLE; ++i){
		choose4[i] = choose3[i-1] + choose4[i-1]; 
	}
	
}

void buildFromTable(){
	short i, j, k;
	int result = 0;
	for(i=0; i<nCountry; ++i){
		for(j=i+1; j<nCountry; ++j){
			for(k=j+1; k<nCountry; ++k){
				from3[i][j][k] = country[i]*country[j]*country[k]; 
			}
		}
	}
}

int threePeopleAns(){
	short i,j,k;
	int ans = 0;
	for(i=0; i<nCountry; i++){
		ans += choose3[country[i]];
	}
	for(i=0; i<nCountry; ++i){
		for(j=i+1; j<nCountry; ++j){
			for(k=j+1; k<nCountry; ++k){
				ans += from3[i][j][k]; 
			}
		}
	}
	return ans;
}

int fourPeopleAns(){
	short i, j, k, p, tmp;
	int ans = 0;
	/*four from the same country*/
	for(i=0; i<nCountry; ++i){
		ans += choose4[country[i]];
	}
	/*three from the same, one from another*/
	for(i=0; i<nCountry; ++i){
		ans += choose3[country[i]] * (nPeople - country[i]);
	}
	/* three from different countries*/
	for(i=0; i<nCountry; ++i){
		for(j=i+1; j<nCountry; ++j){
			for(k=j+1; k<nCountry; ++k){
				/*the fourth is from one of the three countries*/
				ans += (from3[i][j][k]*(country[i] + country[j] + country[k] - 3)) >> 1;
				/* the fourth is from diffent country*/
				for(p=k+1; p<nCountry; ++p){
					ans += from3[i][j][k]*country[p];
				}
			}
		}
	}
	return ans;
}

int main(){
	
	
	short i, tmp;
	FILE *fp = stdin;
#if DEBUG
	fp = fopen("in2.txt", "r");
#endif

	buildChoose3Table();
	
	
	while(2 == fscanf(fp, "%hd %hd", &nPeople, &nCountry)){
		if(nPeople == 0) return 0;
		for(i=0; i<=nCountry; i++){
			country[i] = 0;
		}
		for(i=0; i<nPeople; i++){
			fscanf(fp, "%hd", &tmp);
			country[tmp - 1] += 1;
		}
		qsort(country, nCountry, sizeof(short), compareShort);
		tmp = 0;
		while((tmp < nCountry) && (country[tmp] > 0)){
			++tmp;
		}
		nCountry = tmp;
		buildFromTable();
		printf("%d %d\n", 
			threePeopleAns(nCountry, country), 
			fourPeopleAns(nCountry, country)); 
#if DEBUG
		for(i=0; i<=nCountry; i++){
			if(country[i] > 0) {
				printf("%hd(%hd) ", i, country[i]);
				tmp = i;
			}
		}
		
#endif
	}	
	
	return 0;
}