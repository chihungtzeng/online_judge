#include <stdio.h>
#include <stdlib.h>
#include <search.h>

struct Map{
	int key, value;
};

void *root;

struct Map *newEntry(int key, int value){
	struct Map *m;
	m = (struct Map *) malloc(sizeof(struct Map));
	m->key = key;
	m->value = value;
	return m;
}

int compareMap(const void *a, const void *b){
	struct Map *x, *y;
	x = (struct Map *) a;
	y = (struct Map *) b;
	return x->key - y->key;
}

int f91(int x){
	struct Map query, *match;
	int ans;
	query.key = x;
	match = tfind(&query, &root, compareMap);
	if(match != NULL){
		match = *(struct Map **) match;
		return match->value;
	}
	
	if(x <= 100) ans = f91(f91(x + 11));
	else ans = x - 10;
	
	match = newEntry(x, ans);
	tsearch(match, &root, compareMap);
	return ans;
}

int main(){
	int query, ans;	
	root = NULL;
	while(1 == scanf("%d",&query)){
		if(0 == query){
			break;
		}	
		ans = f91(query);
		printf("f91(%d) = %d\n",query, ans);
	}
	tdestroy(root, free);
	return 0;
}