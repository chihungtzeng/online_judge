#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define M 100
#define LINE_LEN 100000



long int gcd(long int u, long int v){
	long int c=0;
	long int w;
	long int multiple2 = 0;
	
	while ((!(u & 1)) && (!(v & 1))){
	/*both u and v are even*/
		u = u >> 1;
		v = v >> 1;
		multiple2++;
	}
	if ( !(u & 1)){
		u = u ^ v;
		v = u ^ v;
		u = u ^ v;
	}	
	
	while(v != 0){
		while(!(v & 1)){
			v = v >> 1;
			c++;
		}
		
		if(c > 0){
			u = u ^ v;
			v = u ^ v;
			u = u ^ v;
			c = -c;
		}
		w = (u + v) >> 1;
		v = (w & 1)? w - v : w; 
	}
	
	return u << multiple2;
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
				result = gcd(input[i], input[j]);
				
				max = (result > max)? result : max;
			}
		}
		printf("%ld\n",max);
	}	
	return 0;
	
}