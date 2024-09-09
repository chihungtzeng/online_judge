#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 100
#define LINE_LEN 100000

long int gcd(long int a, long int b){
	if (0 == b) return a;
	else return gcd(b, a%b);
}

long int bgcd(long int a, long int b){
	if ( 0 == a ) return b;
	if ( 0 == b ) return a;
	if (( (a&1) == 0) && ((b&1) == 0)){
		return (bgcd(a>>1,b>>1) << 1); 
	}
	else if ((a&1) == 0){
		return bgcd(a>>1, b);
	}
	else if ((b&1) == 0){
		return bgcd(a, b>>1);
	}
	else {
		long int min1,min2;
		min1 = (a>b)? b : a;
		min2 = (a>b)? a-b : b-a;
		return bgcd(min1,min2);
	}
}

int main(){
	int nInput,nTest;
	long int input[N];
	long int max,result;
	int i,j;
	char line[LINE_LEN];
	char *token;
	FILE *fp;
	
	
	fp = stdin;
	fgets(line,LINE_LEN,fp);	
	nTest = atoi(line);
	while(nTest >= 1){
		nTest--;
		nInput = 0;
		fgets(line,LINE_LEN,fp);
		token = strtok(line," \n\t");
		while(NULL != token){
			input[nInput] = atoi(token);
			nInput++;
			token = strtok(NULL," \n\t");
		}
		max = 0;
		for(i=0;i<nInput;i++){
			for(j=i+1;j<nInput;j++){
				result = bgcd(input[i], input[j]);
				max = (result > max)? result : max;
			}
		}
		printf("%ld\n",max);
	}	
	return 0;
	
}