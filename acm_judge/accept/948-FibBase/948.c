#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 100000000
#define MAXFIBNUM 45

char *fibBase(long int n, long int *fib){
	char *s;
	int i,start,done;
	s = (char *) malloc(sizeof(char)*MAXFIBNUM);
	memset(s,0,sizeof(s));
	
	done = 0;
	i=-1;
	while(!done){
		i++;
		if((fib[i]<=n)&&(fib[i+1]>n)){
			done = 1;
		}
	}
	start = i;
	i=0;
	while((start>0)){
		if(n >= fib[start]){
			s[i] = '1';
			n = n - fib[start];
		}
		else {
			s[i] = '0';
		}
		i++;
		start--;
	}
	s[i]='\0';
	return s;
}

int main(){
	long int fib[MAXFIBNUM];
	int i,j,nFib,nInput;
	long int input;
	char *s;
	/*find fibonacci numbers up to MAXNUM*/
	
	fib[0] = 1;
	fib[1] = 1;
	nFib=2;
	for(i=2;i<MAXFIBNUM;i++){
		fib[i] =fib[i-1]+fib[i-2];
	}	
	/*
	for(i=0;i<MAXFIBNUM;i++){
		printf("%ld ",fib[i]);
	}
	printf("\n");
	*/
	
	
	scanf("%d",&nInput);
	for(i=0;i<nInput;i++){
		scanf("%ld",&input);
		s=fibBase(input,fib);
		if(input != 0){
		printf("%ld = %s (fib)\n",input,s);
		}
		else {
			printf("%ld = 0 (fib)\n",input);
		}
		free(s);
	}
	
	return 0;
}
