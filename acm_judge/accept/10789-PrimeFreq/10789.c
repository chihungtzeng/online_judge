#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2002
#define NSYMB 62
#define DEBUG 0

struct Freq{
	char symb;
	short occr;
};

int compareFreq(const void *a, const void *b){
	struct Freq *x, *y;
	x = (struct Freq *)a;
	y = (struct Freq *)b;
	return y->occr - x->occr; 
}
int compareChar(const void *a, const void *b){
	return *(char *)a - *(char *)b;
}

short prime[MAX];
short nPrime;

void buildPrimeTable(){
	short t, i;
	char isPrime;
	nPrime = 3;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	t = 7;
	while(t <= MAX){
		isPrime = 1;
		for(i=2; isPrime && (prime[i]*prime[i] <= t); i++){
			if(t % prime[i] == 0){
				isPrime = 0;
			}
		}
		if(isPrime) prime[nPrime++] = t;
		t += 4;
		isPrime = 1;
		for(i=2; isPrime && (prime[i]*prime[i] <= t); i++){
			if(t % prime[i] == 0){
				isPrime = 0;
			}
		}
		if(isPrime) prime[nPrime++] = t;
		t += 2;
	} 
}

int compareShort(const void *a, const void *b){
	short x, y;
	x = *(short *)a;
	y = *(short *)b;
	return x - y;
}

int main(){
	short nTest, k = 1, nAns, i;
	char line[MAX], *c, ans[NSYMB];
	struct Freq freq[NSYMB];
	FILE *fp;
	
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;	
	
	buildPrimeTable();
	
	
	fscanf(fp, "%hd",&nTest);	
	
	
	while(k <= nTest){
		fscanf(fp, "%s", line);
		c = line;
		for(i=0; i<=9; i++){
			freq[i].occr = 0;
			freq[i].symb = i + '0';
		}
		
		for(i='a'; i <= 'z'; i++){
			freq[i - 'a' + 10].occr = 0;
			freq[i - 'a' + 10].symb = i;
		}
		
		for(i='A'; i<= 'Z'; i++){
			freq[i - 'A' + 36].occr = 0;
			freq[i - 'A' + 36].symb = i;
		}
		
		while(*c != '\0'){
			if(isdigit(*c)){
				freq[*c - '0'].occr += 1;
			}
			else if( (*c >= 'a') && (*c <= 'z')) {
				freq[*c - 'a' + 10].occr += 1;
			}
			else if( (*c >= 'A') && (*c <= 'Z')){
				freq[*c - 'A' + 36].occr += 1;
			}
			c++;
		}
		
		qsort(freq, NSYMB, sizeof(struct Freq), compareFreq);

		/*
		for(i=0; i<NSYMB; i++){
			printf("%c(%hd) ",freq[i].symb, freq[i].occr);
		}		
		printf("\n");
		*/
		nAns = 0;
		i=0;
		while((i<NSYMB) &&(freq[i].occr > 0)){
			if(NULL != bsearch(&freq[i].occr, prime, nPrime, sizeof(short), compareShort)){
				ans[nAns++] = freq[i].symb;
			}
			i++;
		}
		
		if(nAns == 0){
			printf("Case %hd: empty\n",k++);
		}
		else{
			qsort(ans, nAns, sizeof(char), compareChar);
			ans[nAns] = '\0';
			printf("Case %hd: %s\n",k++, ans);
		}
	}
	return 0;
}