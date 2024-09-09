#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
#define LEN 4096


int main(){
	char line[LEN];
	int freq[MAX];
	int i, max;
	char *ptr;
	while(NULL != fgets(line, LEN, stdin)){
		memset(freq, 0, sizeof(int)*MAX);
		
		for(ptr=line; *ptr != '\n'; ptr++){
			if(isalpha(*ptr)){
				freq[*ptr]++;
			}
		}
		max = 0;
		for(i='A'; i<='Z'; i++){
			if(freq[i] > max) max = freq[i];
		}
		for(i='a'; i<='z'; i++){
			if(freq[i] > max) max = freq[i];
		}
		for(i='A'; i<='Z'; i++){
			if(freq[i] == max){
				printf("%c", i);
			}
		}
		for(i='a'; i<='z'; i++){
			if(freq[i] == max){
				printf("%c", i);
			}
		}
		printf(" %d\n", max);
	}
	return 0;
}
