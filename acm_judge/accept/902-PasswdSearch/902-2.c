#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 800000
#define DEBUG 0
#define SUBMIT 1




int compareLong(const void *x, const void *y){
	long int a,b;
	a = *(long int *)x;
	b = *(long int *)y;
	if (a>b) return 1;
	if (a<b) return -1;
	return 0;
}

char *decode(long int a, int len){
	/*decode a in base 26 into a string of proper length*/
	char *s;
	int i;
	s = (char *) malloc(sizeof(char)*len+1);
	for(i=0;i<len;i++){
		s[len-i-1] = 'a' + a%26 ;
		a = a/26;
	}
	s[len]='\0';
	return s;
}

long int encode(char *s,long int divider, long int pre_encode){
	long int result;
	
	int len = strlen(s);
	int i;
	
	if(pre_encode > 0){
		result = (pre_encode % divider)*26 + (s[len-1]-'a');
		return result;
	}
	result = 0;
	for(i=0;i<len;i++){
		result = result*26 + s[i] - 'a';
	}
	return result;
}


int main(){
	int nChar; 
	char *input;
	char *eS;
	char c;
	long int *hashInput;
	long int i,j;
	long int eInt,pre_eInt;
	long int inputLen, nES;
	long int count,max,ans;
	long int divider;
	int done,emptyInput;

	
	
	while(1 == scanf("%d",&nChar)){
		input = (char *) malloc(sizeof(char)*MAX);
		
		i=0;
		done=0;
		emptyInput=1;
		while(!done){
			scanf("%c",&c);
			if(('\n' == c)&&(!emptyInput)){
				done = 1;
			}			
			else if(('a' <= c)&&('z' >= c)){
				emptyInput=0;
				input[i] = c;
				i++;
			}			
		}
		input[i]='\0';
		inputLen = i;
		
		nES = inputLen - nChar+1;
		
		if(nES <= 0){
			
			continue;
		}
		hashInput = (long int *) malloc(sizeof(long int )*(nES));
		for(i=0;i<nES;i++){
			hashInput[i] = 0;
		}
		divider = pow(26, nChar-1);
		
		eS = strndup(input,nChar);
		eInt = encode(eS,divider,0); 
		pre_eInt = eInt;
		hashInput[0] = eInt;
		for(i=1;i<nES;i++){
			free(eS);
			eS = strndup(input+i,nChar);
			eInt = encode(eS,divider,pre_eInt);
			pre_eInt = eInt;
			hashInput[i] = eInt;
		}
		
		free(eS);

		if(DEBUG){
			for(i=0;i<nES;i++){
				printf("%ld ",hashInput[i]);
			}
			printf("-------------\n");
		}				
		
		qsort(hashInput,nES,sizeof(long int),compareLong);
		/*
		if(DEBUG){
			for(i=0;i<nES;i++){
				printf("%ld ",hashInput[i]);
			}
			printf("\n");
		}*/
		
		max=1;
		eInt = hashInput[0];
		count = 1;
		ans = eInt;
		for(i=1;i<nES;i++){
			if (hashInput[i] == eInt){
				count++;
			}
			else {
				if(count > max){
					max =count;
					ans = eInt;
				}
				eInt = hashInput[i];
				count = 1;
			}
		}
		if (count > max){
			max = count;
			ans = eInt;
		}
		if(!SUBMIT){
			printf("%s %ld\n",decode(ans,nChar),max);
		}
		if(SUBMIT){
			printf("%s\n",decode(ans,nChar));
		}
		
		free(hashInput);
		free(input);
	}
	
	
	exit(0);
}  