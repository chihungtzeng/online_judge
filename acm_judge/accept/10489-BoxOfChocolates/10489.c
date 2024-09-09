#include <stdio.h>


int main(){
	int nBox, nItem, sum, nFriend, nChocolate, tmp;
	short nTest;
	int i,j;
	scanf("%hd", &nTest);
	while(nTest--){
		sum = 0;
		scanf("%d %d",&nFriend, &nBox);
		for(i=0; i<nBox; i++){
			scanf("%d", &nItem);
			tmp = 1;
			for(j=nItem - 1; j>=0; j--){
				scanf("%d", &nChocolate);
				tmp = (tmp * nChocolate) % nFriend;
				
			}
			sum = (sum + tmp) % nFriend;
		}
		if(nFriend == 0){
			printf("%d\n", sum);
		} else {
			printf("%d\n", sum % nFriend);
		}
	}
	return 0;
}