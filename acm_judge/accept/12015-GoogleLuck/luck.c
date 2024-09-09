#include <stdio.h>
#include <stdlib.h>
#define LEN 120

struct URL{
	char link[LEN];
	char rank;
};

int main(){
	int nTest, k = 1, i;
	struct URL url[10];
	char topRank = 0;
	
	scanf("%d", &nTest);
	while(nTest > 0){
		nTest -= 1;
		topRank = 0;
		for(i=0; i<10; ++i){
			scanf("%s %hhd", url[i].link, &url[i].rank);
			if(url[i].rank > topRank) topRank = url[i].rank;
		}
		printf("Case #%d:\n", k++);
		for(i=0; i<10; i++){
			if(url[i].rank == topRank){
				puts(url[i].link);
			}
		}
	}
	return 0;
}