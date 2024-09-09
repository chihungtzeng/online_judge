#include <stdio.h>
#include <stdlib.h>
#define LEN 20001

short nItem, item[LEN];

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

void solve(){
	int result = 0;
	short i;
	qsort(item, nItem, sizeof(short), compareShort);
	for(i = nItem - 1; i >= 2; i -= 3){
		result += item[i - 2];
	}
	printf("%d\n", result);
}

int main(){
	
	short nTest, i;
	
	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%hd", &nItem);
		for(i=0; i<nItem; i++){
			scanf("%hd", item + i);
		}
		solve();
	}
	return 0;
}