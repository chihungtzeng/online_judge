#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define LINELEN 1000000
#define DEBUG 0
#define READFILE 0

int compareLong(const void *x, const void *y){
	long long int a, b;
	a = *(long long int *) x;
	b = *(long long int *) y;
	if (a>b) return 1;
	else if (a<b) return -1;
	else return 0;
}

char *decode(long long int a, int len){
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

int main(){
	long long int *subString;
	long long int cur,ans;
	
	char *eS;
	int passwdlen,eSLen;
	char c;
	int done,hasmore;
	int i,j,count,max;
	long long int divider;
	FILE *fp;
	
	subString = (long long int *) malloc(sizeof(long long int)*LINELEN);
	eS = (char *) malloc(sizeof(char)*LINELEN);
	
	if(READFILE){
		fp = fopen("in3.txt","r");
		hasmore = fscanf(fp,"%d",&passwdlen);	
	}
	else {
		hasmore = scanf("%d",&passwdlen);
	}
	while(1 == hasmore){
		/*
			fill eS with 0 in the beginning
			map a substring into an integer with base 26
			For example: 
			bac 
			-> 102 in base 26 
			-> 1*26^2 + 0*26^1 + 2*26^0 in decimal 
		*/

		divider=pow(26,passwdlen-1);

		for(i=0;i<passwdlen;i++){
			eS[i]=0;
		}
		done = 0;
		
		while(!done){
			if(READFILE){
				fscanf(fp,"%c",&c);
			}
			else{
				scanf("%c",&c);
			}
			
			if ('\n' == c){
				done = 1;				
			}
			else if (isspace(c)) {
			}
			else {
				eS[i] = c - 'a';
				i++;
			}
		}
		eSLen = i;
		cur = 0;
		
		if(eSLen - passwdlen < passwdlen ){
			printf("\n");
			continue;
		}
		
		if(DEBUG){
			printf("esLen=%d passwdlen=%d\n",eSLen,passwdlen);
			for(j=0;j<eSLen;j++){
				printf("%c",'a'+eS[j]);
			}
			printf("\n");
		}
		
		
		for(i=0;i<=eSLen-passwdlen;i++){
			cur = (cur % divider)*26 + eS[i+passwdlen-1];
			subString[i] = cur; 
			
		}
		if(DEBUG){
			for(j=passwdlen;j<eSLen;j++){
				printf("%Ld ",subString[j]);
			}
			printf("-------------------\n");
		}
		
		qsort(&subString[passwdlen],eSLen-passwdlen*2+1,sizeof(long long int),compareLong);
		
		if(DEBUG){
			for(j=passwdlen;j<eSLen;j++){
				printf("%Ld ",subString[j]%1000);
			}
		}
		cur = subString[passwdlen];
		count = 1;
		max = 0;
		ans=cur;
		for(i=passwdlen+1;i<=eSLen-passwdlen*2+1;i++){
			if(cur == subString[i]){
				count++;
			}
			else{
				if(count >= max){
					
					ans = cur;
					max = count;
				} 
				
				cur = subString[i];
				count = 1;
			}
		}
		if(count >= max){
			ans=cur;
			max=count;
		}
/*		decode(ans,passwdlen); */
		printf("%s %d\n",decode(ans,passwdlen),max);
		
		if(READFILE){
			hasmore = fscanf(fp,"%d",&passwdlen);	
		}
		else {
			hasmore = scanf("%d",&passwdlen);
		}

	} /*end of while loop*/
		free(subString);
		free(eS);
	return 0;
}
