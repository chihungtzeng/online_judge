#include <stdio.h>
#define MAX 12
#define LEN 11
char ans[MAX][LEN] = {"1","1","3","13","75","541","4683","47293","545835","7087261","102247563","1622632573"};


int main(){
	short i, nTest;

	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%hd", &i);
		puts(ans[i]);
	}

	return 0;
}