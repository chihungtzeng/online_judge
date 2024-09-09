#include <stdio.h>
#include <stdlib.h>

short *marble, query;
int nMarble;
int nQuery;

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int mybsearch(int query){
	int right = nMarble - 1, left = 0, middle;
	while(left <= right){
		middle = (left + right) >> 1;
		if(marble[middle] == query) return middle;
		else if(marble[middle] < query) left = middle + 1;
		else right = middle - 1;
	}
	return (left + right) >> 1;
}

int main(){
	char kase = 1;
	int i, ans;
	while(2 == scanf("%d %d", &nMarble, &nQuery)){
		if( (0 == nMarble) && (0 == nQuery)) return 0;
		marble = (short *) malloc(sizeof(short)*nMarble);
		
		for(i=0; i<nMarble; i++){
			scanf("%hd", marble + i);
		}
		qsort(marble, nMarble, sizeof(short), compareShort);
		printf("CASE# %hhd:\n", kase++);


		for(i=0; i<nQuery; i++){
			scanf("%hd", &query);
			ans = mybsearch(query);
			if(marble[ans] != query){
				printf("%d not found\n",query);
			}
			else{
				while(marble[ans - 1] == query) ans--;
				
				printf("%d found at %d\n", query, ans + 1);
			}
		}
		free(marble);
	}
	return 0;
}