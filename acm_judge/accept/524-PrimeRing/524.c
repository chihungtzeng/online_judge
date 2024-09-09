/*AC*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 17

short prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
short nPrime = 11;

int compareShort(const void *a, const void *b){
	return *(short *)a - *(short *)b;
}

void nextPrime(char output[], char pos, char flag[], short s){
	char i;
	char flagbak[MAX];
	short sum;
	if(pos == s){
		sum = output[s - 1] + output[0];
		if(bsearch(&sum, prime, nPrime, sizeof(short), compareShort) != NULL){
		/*if(1){*/
			printf("%hhd",output[0]);
			for(i=1; i<s; i++){
				printf(" %hhd", output[i]);
			}
			printf("\n");
		}
		return ;
	} 
	memcpy(flagbak, flag, s + 1);
	for(i=2; i<=s; i++){
		if(flag[i] == 0){
			sum = i + output[pos - 1];
			if(bsearch(&sum, prime, nPrime, sizeof(short), compareShort) != NULL){
				output[pos] = i;
				flag[i] = 1;
				nextPrime(output, pos + 1, flag, s);
				memcpy(flag, flagbak, MAX);
			}
		}
	}
}

void genPrimeRing(short s){
	char output[s];
	char flag[MAX], pos;
	
	memset(flag, 0, MAX);
	flag[1] = 1;
	output[0] = 1;
	nextPrime(output, 1, flag, s);
}

int main(){
	char k = 1;
	short s;
	char firstCase = 1;
	while(1 == scanf("%hd", &s)){
		if(firstCase){
			firstCase = 0;
		}
		else{
			printf("\n");
		}
		printf("Case %hhd:\n",k);
		genPrimeRing(s);
		
		k++;
	}	
	return 0;
}