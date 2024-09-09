#include <stdio.h>
#include <stdlib.h>

char *bitoa(unsigned long int n, int base){
	char *s;
	int len = 0;
	int i;
	char c;
	s = (char *) malloc(sizeof(char)*(sizeof(n)*8));
	if(n == 0){
		strcpy(s,"0");
	}
	else{
		while(n > 0){
			s[len++] = (n % base) + '0';
			n = n / base;
		}
		s[len] = '\0';
	}
	for(i=0;i<len/2;i++){
		c = s[len - 1 -i] ;
		s[len -1 -i] = s[i];
		s[i] = c;
	}
	return s;
}

char *itoa(int num){
	char *s;
	s = (char *)malloc(sizeof(char)*32);
	snprintf(s,32,"%d",num);
	return s;
}


int main(){
	int n=-123456789;
	printf("%s\n",itoa(n));
}