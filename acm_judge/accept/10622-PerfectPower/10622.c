#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define MAX 50000
#define BOUND 2147483648
#define DEBUG 0

struct Power{
	long long value;
	int pow;
};

int comparePower(const void *a, const void *b){
	struct Power *x, *y;
	x = (struct Power *)a;
	y = (struct Power *)b;
	return x->value - y->value;
}

int main(){
	void *root;	
	struct Power *power, pQuery, *match;
	int nPower = 0;
	long long i;
	int k;
	long long value, query;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt","r") : stdin;	
	
	root = NULL;
	for(i=2; i<=65535; i++){
		value = i*i;
		k = 2;
		while(value <= BOUND){
			power = (struct Power *) malloc(sizeof(struct Power));
			power->value = value;
			power->pow = k;
			match = tsearch((void *) power, &root, comparePower);
			if(match != NULL){
				if( (*(struct Power **) match) != power){
					free(power);
				}
			}
			
			value = value*i;
			k++;
		}
	}
	
	while(1 == fscanf(fp, "%lld", &query)){
		if(0 == query) break;
		pQuery.value = llabs(query);
		match = tfind(&pQuery, &root, comparePower);
		if(!match){
			printf("1\n");
		}
		else {
			match = *(struct Power **)match;
			/*printf("query: %lld match->pow: %d\n",query, match->pow);*/
			if(query > 0){
				
				printf("%d\n",match->pow);
			}
			else if ((query < 0) && (match->pow % 2 == 1)){
				printf("%d\n",match->pow);
			}
			else if ((query < 0) && (match->pow % 2 == 0)){
				k = match->pow;
				while(k % 2 == 0){
					k = k >> 1;
				}
				printf("%d\n",k);
			}
		}
	}
	tdestroy(root, free);	
	return 0;
}