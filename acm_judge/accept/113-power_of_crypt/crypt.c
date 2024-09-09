#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#define NBITS 2000
#define DEBUG 0

void reverse(unsigned short *target, int n){
	int i;
	unsigned int tmp;
	for (i=0;i<=n/2;i++){
		tmp=target[i];
		target[i] = target[n-i-1];
		target[n-i-1] =tmp;
	}
}

unsigned short *str2bigint(char *s){
	int i,len;
	unsigned short *result;
	//char *s;
	result = (unsigned short *)malloc(sizeof(unsigned short)*NBITS);	
	//s = (char *)malloc(sizeof(char)*NBITS);
	
	
	
	for(i=0;i<NBITS;i++){
		result[i] = 0;
	}
	len = strlen(s);
	
	if (s[len -1] == '\n'){
		len--;
	}
	
	for(i=0;i<len;i++){
		if ((s[i] > '9')||(s[i]<'0')){
			printf("wrong string %s\n",s);
				exit(EXIT_FAILURE);
		}
		result[NBITS-len+i] = s[i] - '0';
	}
	
	return result;
}

char *bigint2str(unsigned short a[]){
	int i=0,j;
	char *s;
	
	s = (char *) malloc(sizeof(char)*NBITS);
	//s = (char *)calloc(sizeof(char),NBITS);
	if (a == NULL) return "";
	while((i<NBITS)&&(a[i] ==0)){
		i++;
	}
	j=0;
	for(;i<NBITS;i++){
		s[j] = a[i]+'0';
		j++;
	}
	s[j]='\0';
	return s;
}

unsigned short *multiply(unsigned short a[], unsigned short b[]){
	int i,j,k,carry,tmp,remainder;
	
	unsigned short *theresult;
	unsigned short *trim_result;

	theresult = (unsigned short *) malloc(sizeof(unsigned short)*2*NBITS);
	trim_result = (unsigned short *) malloc(sizeof(unsigned short)*NBITS);
	
	reverse(a,NBITS);
	reverse(b,NBITS);
	for(i=0;i<2*NBITS;i++){
		theresult[i]=0;
	}
	
	for(j=0;j<NBITS;j++){
		for(i=0;i<NBITS;i++){
				tmp = a[i]*b[j];
				remainder = tmp % 10;
				carry = tmp/10;
				carry += (theresult[i+j]+remainder)/10;
				theresult[i+j] = (theresult[i+j] + remainder) % 10;
								
				
				for(k=i+j+1;(k<2*NBITS)&&(carry>0);k++){
					tmp = (theresult[k] + carry) % 10;					
					carry = (theresult[k] + carry)/10;
					theresult[k] = tmp;
				}
				 
		}
	}
	reverse(a,NBITS);
	reverse(b,NBITS);
	reverse(theresult,2*NBITS);

	for(i=0;i<NBITS;i++){
		trim_result[i] = theresult[i+NBITS];
	}	
	return trim_result;
}

unsigned short *add(unsigned short a[],unsigned short b[]){
	unsigned short *result;
	int i,carry;
	
	result=(unsigned short *) malloc(sizeof(unsigned short)*NBITS);
	carry=0;
	for (i=NBITS-1;i>=0;i--){
		result[i] = (carry+a[i]+b[i]) % 10;
		carry = (carry+a[i]+b[i])/10;
	}
	return result;
}

unsigned short *divideby2(unsigned short *input){
	unsigned short *output;
	int i,quotient,remainder;
	
	output = (unsigned short *) malloc(sizeof(unsigned short)*NBITS);
	
	
	quotient=0;
	remainder=0;
	for(i=0;i<NBITS;i++){
		quotient = (remainder*10+input[i])/2;
		remainder = (remainder*10+input[i]) % 2;
		output[i]= quotient;
	}
	return output;
}

unsigned short *bigintcopy(unsigned short *n){
	int i;
	unsigned short *result;
	result = (unsigned short *)malloc(sizeof(unsigned short)*NBITS);
	for(i=0;i<NBITS;i++){
		result[i] = n[i];
	}
	return result;
}

unsigned short *n2p(unsigned short *n, int p){
//find n^p
	//unsigned short *result;
	//result= (unsigned short *)malloc(sizeof(unsigned short)*NBITS);
	
	if( 1 == p) {
		return bigintcopy(n);
	}
	else if (0 == p) {
		printf("shit n^p!\n");
		return str2bigint("1");
	}
	else return multiply(
						n2p(n,p/2), 
						n2p(n, p/2 + (p%2)) 
						);
}
int compare(unsigned short a[],unsigned short b[]){
	//return 1 if a>b
	//return 0 if a=b
	//return -1 if a<b
	int i;
	for (i=0;i<NBITS;i++){
		if (a[i] > b[i]){
			return 1;
		}
		else if (a[i]<b[i]){
			return -1;
		}
	}
	return 0;
}

unsigned short *findroot(unsigned short *n, int p){
	unsigned short *left, *right, *pivot,*tmp, *tmp2;
	left=str2bigint("2");	
	right=str2bigint("2");
	
	//find [left..right] containing the answer
	tmp = n2p(right,p);
	while (compare(tmp,n)<0){
		if(DEBUG){
			printf("find proper range [%s .. %s]\n",bigint2str(left),bigint2str(right));
			printf("%s^%d= %s\n",bigint2str(right),p,bigint2str(tmp));
			//getchar();
		}
		tmp2 = right;	
		right = multiply(right,str2bigint("2"));
		free(tmp2); 
		tmp = n2p(right,p); 
	}	
	//now [left..right] contains the answer
	//use binary search to find it	
	
	
	while( compare(left, right) <=0 ){
		pivot = divideby2(add(left,right));
		if(DEBUG){
			printf("testing [%s .. %s] pivot=%s\n",bigint2str(left),bigint2str(right),bigint2str(pivot));
		}
		
		tmp = n2p(pivot,p);
		
		if (compare(tmp, n) <0){
			// left <= pivot < answer <= right
			tmp2 = left;
			left = add(pivot,str2bigint("1"));
			free(tmp2); 
		}
		else if (compare(tmp,n) > 0){
			tmp2 = right;
			right = pivot;
			free(tmp2);
		}
		else if (compare(tmp,n) == 0){
			return pivot;
		} 
	}
	
	return NULL;
}


int main(int argc, char *argv[]){
	char *n,*pc,*k;
	int p;
	unsigned short *bigint;
	FILE *fp;
	struct timespec stime,etime;
	
	//clock_gettime(CLOCK_REALTIME, &stime);
	fp = fopen("input.txt","r");
	if (NULL == fp) {
		exit(EXIT_FAILURE);
	}	
	n = (char *) malloc(sizeof(char)*NBITS);
	k = (char *) malloc(sizeof(char)*NBITS);
	pc = (char *) malloc(sizeof(char)*NBITS);
	
	
	
	while ((NULL!=fgets(pc,NBITS,fp))&&(fgets(n,NBITS,fp))){
		p = atoi(pc);
		
		if (n[strlen(n)-1] == '\n') {
			n[strlen(n)] = '\0';
		}
		bigint = str2bigint(n);
		
		printf("The %dth root of %s is ",p, n);
		
		
		
		k = bigint2str( findroot(bigint, p ));
		printf("%s\n", k);
		
	}
/*
	char *s1="17";
	char *s2="16";
	printf("%s vs. %s : %d\n",s1,s2,compare(str2bigint(s1), str2bigint(s2)));	

	clock_gettime(CLOCK_REALTIME,&etime);

	long int time_elapsed;
	time_elapsed=etime.tv_nsec - stime.tv_nsec;
	
	printf("Elapsed Time: %ld mini seconds\n", time_elapsed/1000000);
*/	
	exit(EXIT_SUCCESS);
	
}
