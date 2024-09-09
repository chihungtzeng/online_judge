#include <stdio.h>
#include <stdlib.h>
#define MAX 50001

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

int main(){
	short street[MAX], avenue[MAX];
	int nStreet, nAvenue, nFriend;
	int i, idx, nTest;
	short s, a;
	scanf("%d",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%d %d %d", &nStreet, &nAvenue, &nFriend);
		for(i = nFriend - 1; i>=0; i--){
			scanf("%hd %hd",street+i, avenue+i);
		}
		qsort(street, nFriend, sizeof(short), compareShort);
		qsort(avenue, nFriend, sizeof(short), compareShort);
		/*
		for(i=0;i<nFriend; i++){
			printf("street:%hd avenue:%hd\n", street[i], avenue[i]);
		}		
		*/
		idx = (nFriend % 2 == 1)? nFriend  >> 1 : (nFriend - 1) >> 1;
		
		/*
		if(nFriend % 2 == 1){
			s = street[idx];
			a = avenue[idx];
		}
		else{
			s = (street[idx] + street[idx-1]) >> 1 ;
			a = (avenue[idx] + avenue[idx-1]) >> 1;
		}
		*/
		printf("(Street: %hd, Avenue: %hd)\n",street[idx], avenue[idx]);
	}
	return 0;
}