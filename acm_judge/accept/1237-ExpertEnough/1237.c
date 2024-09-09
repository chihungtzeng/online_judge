#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001

struct Car {
	char model[21];
	int low, high;
};

int queryDatabase(int *ans, int nCar, struct Car car[], int query){
	int i, nAns = 0;
	for(i=0; (i < nCar) && (nAns <= 1); i++){
		if( (car[i].low <= query) && (query <= car[i].high)){
			*ans = i;
			nAns++;
		}
	}
	return nAns;
}

int main(){
	struct Car car[MAX];
	int i;
	int nTest, nQuery, query, nCar;
	int ans, nAns;
	int first = 1;
	
	scanf("%d", &nTest);
	while(nTest--){
		if(first){
			first = 0;
		} else{
			printf("\n");
		}
		scanf("%d", &nCar);
		for(i=0; i<nCar; i++){
			scanf("%s %d %d", car[i].model, &car[i].low, &car[i].high);
		}
		scanf("%d", &nQuery);
		for(i=0; i<nQuery; i++){
			scanf("%d", &query);
			nAns = queryDatabase(&ans, nCar, car, query);
			if(nAns == 1){
				printf("%s\n", car[ans].model);
			} else {
				printf("UNDETERMINED\n");
			}
		}
	}
	return 0;
}