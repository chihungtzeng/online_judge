#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000001



struct Phi {
	int value;
	int key;
};

int comparePhi(const void *a, const void *b){
	struct Phi *x, *y;
	x = (struct Phi *) a;
	y = (struct Phi *) b;
	if(x->value != y->value) return x->value - y->value;
	else return x->key - y->key;
}

void euler_phi(int *phi, char *prime)
{
  int i, j;

  for (i = 0; i < MAX; i++) phi[i] = i;
  phi[2] = 1;

  for (j = 4; j < MAX; j += 2) {
  	prime[j] = 1; 
  	phi[j] -= phi[j] >> 1;
  }
  for (i = 3; i < MAX; i++) {
    if (prime[i]) continue;
    phi[i] -= phi[i] / i;
    for (j = i+i; j < MAX; j += i){
     prime[j] = 1, 
     phi[j] -= phi[j] / i;
    }
  }
#if 0
  for (i = 1; i <= 100; i++) printf("(%d,%d) ", i, phi[i]);
  printf("\n");
#endif
}

void buildTable(struct Phi *table, int *phi){
	int i;
	table[0].key = 0;
	table[0].value = MAX + 1;
	for(i=1; i<MAX; i++){
		table[i].key = i;
		table[i].value = phi[i];
	}
	qsort(table, MAX, sizeof(struct Phi), comparePhi);
}

int mybsearch(int target, struct Phi *table){
	int left = 0, right = MAX - 1;
	int middle;
	int found = 0;
	while((left <= right) && (!found)){
		middle = (left + right) >> 1;
		if(table[middle].value == target){
			found = 1;
		} 
		else if (table[middle].value < target){
			left = middle + 1;
		} 
		else {
			right = middle - 1;
		}
	}
	if(!found) return -1;
	
	while((middle >= 0) && (table[middle].value == target)){
		middle--;
	}
	middle++;
	return middle;
}

int main(){
	struct Phi *table;
	int *phi;
	char *prime;
	int target, index, i;
	
	phi = (int *) malloc(sizeof(int)*MAX);
	prime = (char *) malloc(MAX);
	table = (struct Phi *) malloc(sizeof(struct Phi)*MAX);
	euler_phi(phi, prime);
	buildTable(table, phi);

		
	
	free(phi);
	free(prime);
	
/*
	while(1 == scanf("%d", &target)){
		index = mybsearch(target, table);
		if(index < 0) {
			printf("No solution.\n");
		}
		else {
			printf("%d", table[index].key);
			for(i=index + 1; table[i].value == target; i++){
				printf(" %d", table[i].key);
			}
			printf("\n");
		}
	}	
	*/
	free(table);
	return 0;
}