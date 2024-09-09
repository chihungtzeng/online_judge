#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define NVALUE 22
#define MAX 10001

int currency[NVALUE];

struct MyHashEntry{
	int money, allow;
	long long value;
};

void initCurrency(){
	int i;
	for(i=0; i<NVALUE; i++){
		currency[i] = i*i*i;
	}
}

int compareMyHashEntry(const void *a, const void *b){
	struct MyHashEntry *x, *y;
	x = (struct MyHashEntry *)a;
	y = (struct MyHashEntry *)b;
	if(x->money != y->money) return x->money - y->money;
	else return x->allow - y->allow;
}

struct MyHashEntry *newMyHashEntry(int money, int allow, long long value){
	struct MyHashEntry *h;
	h = (struct MyHashEntry *) malloc(sizeof(struct MyHashEntry));
	h->money = money;
	h->allow = allow;
	h->value = value;
	return h;
}

long long findAns(int money, int allow, void **root){
	long long ans = 0;
	int i, r;
	struct MyHashEntry *match, *h;
	if(allow == 1){
		return 1;
	}
	else if (allow == 2){
		return 1 + money/currency[2];
	}
	
	h = newMyHashEntry(money, allow, 0);
	match = *(struct MyHashEntry **) tsearch(h, root, compareMyHashEntry);
	if(match == NULL){
		printf("insufficient memory\n");
		return -1;
	}
	else if (match == h){
		tdelete(h, root, compareMyHashEntry);
		free(h);
	}
	else {
		free(h);
		return match->value;
	}
		
	r = money/currency[allow];
	for(i=0; i <= r; i++){
		ans += findAns(money - i*currency[allow], allow - 1, root);
	}
	h = newMyHashEntry(money, allow, ans);
	tsearch(h, root, compareMyHashEntry);
	return ans;
}

int main(){
	int m, allow;
	long long ans, i;
	void *root;	
	initCurrency();
	root = NULL;
	while(1 == scanf("%d", &m)){
		allow = 0;
		while((currency[allow] < m) && (allow < NVALUE)){
			allow++;
		}
		allow--;
		ans = findAns(m, allow, &root);
		printf("%lld\n",ans);
	}
	tdestroy(root, free);
	return 0;
}