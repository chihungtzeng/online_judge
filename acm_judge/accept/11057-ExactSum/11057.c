#include <stdio.h>
#include <string.h>
#define MAX 10000

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int mybsearch(int target, int nBook, int *book){
	int left, right, middle;
	left = 0;
	right = nBook - 1;
	while(left <= right){
		middle = (left + right) >> 1;
		if(book[middle] == target){
			return middle;
		}
		else if (book[middle] < target){
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}
	return (left + right) >> 1;
}

int main(){
	int nBook;
	int book[MAX];
	int money;
	int i;
	int target, src, idx, idx2;
	char done;
	
	while(1 == scanf("%d", &nBook)){
		for(i = nBook - 1; i >= 0; i--){
			scanf("%d", book + i);
		}
		scanf("%d",&money);
		qsort(book, nBook, sizeof(int), compareInt);
		idx = mybsearch(money >> 1, nBook, book);
		if(((book[idx] == book[idx - 1]) && (book[idx] + book[idx - 1] == money)) ||
			((book[idx] == book[idx + 1]) && (book[idx] + book[idx + 1] == money))
		){
			done = 1;
			src = book[idx];
			target = book[idx];
		} 
		else{
			done = 0;
		}
		while(!done){
			src = book[idx];
			target = money - src;
			idx2 = mybsearch(target, nBook, book);
			if((book[idx] + book[idx2] == money)){
				
				done = 1;
			}
			else {
				idx--;
			}
		} 
		printf("Peter should buy books whose prices are %d and %d.\n\n", src, target);
	}
	
	return 0;
}