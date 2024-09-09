#include <stdio.h>
#include <stdlib.h>
#include <search.h>

struct HashEntry {
	long key;
	long value;
};

struct HashEntry *newHashEntry(long key, long value){
	struct HashEntry *h;
	h = (struct HashEntry *) malloc(sizeof(struct HashEntry));
	h->key = key;
	h->value = value;
	return h;
}

int compareHashEntry(const void *a, const void *b){
	struct HashEntry *x, *y;
	x = (struct HashEntry *)a;
	y = (struct HashEntry *)b;
	return x->key - y->key; 
}

void *root;

long Ackermann(long int n){
	if(n == 1) return 0;
	struct HashEntry *query, *match;
	long result;
	
	query = newHashEntry(n, 0);
	match = tfind(query, &root, compareHashEntry);	
	if(match){
		free(query);
		match = *(struct HashEntry **) match;
		return match->value;
	}
	if(n & 1){
		result = 1 + Ackermann((n << 1) + n + 1);
	}
	else{
		result = 1 + Ackermann(n >> 1);
	}
	query->value = result;
	tsearch(query, &root, compareHashEntry);
	return result;
}

int main(){
	long x, y, m, M, largest, i, shit;
	long ans;
	root = NULL;
	while(2 == scanf("%ld %ld",&x, &y)){
		if( (0 == x) && (0 == y)) break;
		
		if(x <= y){
			m = x;
			M = y;
		}
		else{
			m = y;
			M = x;
		}
		
		if(m == 1){
			ans = 3;
		}
		else{
			ans = Ackermann(m);
		}
		largest = m;
		for(i = m + 1; i<=M; i++){
			shit = Ackermann(i);
			if(shit > ans){
				ans = shit;
				largest = i;
			}
		}
		printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",m, M, largest, ans);
	}
	
	return 0;
}