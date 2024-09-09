#include <stdio.h>
#define MAX 21



int main(){
	short nTest, k = 1, i;
	char word[MAX];
	char nOccr[255];
	size_t len;
	char *pos;
	
	unsigned long long fac[MAX] = {1};
	unsigned long long ans;
	for(i=1; i<MAX; i++){
		fac[i] = fac[i-1] * i;
	}

	scanf("%hd", &nTest);
	while(nTest > 0){
		nTest--;
		for(i='A'; i<'Z'; i++){
			nOccr[i] = 0;
		}
		
		scanf("%s", word);
		pos = word;
		while(*pos != '\0'){
			nOccr[*pos] += 1;
			pos++;
		}
		len = pos - word;
		ans = fac[len];
		for(i='A'; i<'Z'; i++){
			if(nOccr[i] > 1){
				ans = ans / fac[nOccr[i]];
			}
		}		
		printf("Data set %hd: %llu\n", k++, ans);
	}
	
	return 0;
	
}