#include <stdio.h>
#include <string.h>
#define LEN 6

char word[LEN];
int p26[LEN];

int findAns(){
	int ans = 0;
	char i;
	char len = strlen(word);

	for(i=1; i<len; i++){
		if(word[i] < word[i-1]) return 0;
	}

	for(i=0; i<len; i++){
		ans += (word[i] - 'a' + 1) * p26[len - i -1];
	}
	return ans;
}

int main(){
	
	char i = 0;
	p26[0] = 1;
	for(i=1; i<LEN; i++){
		p26[i] = p26[i-1]*(26 - i);
	}
	while(1 == scanf("%s", word)){
		printf("%d\n", findAns());
	}
	return 0;
}