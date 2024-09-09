#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
#define MAX 40001

int nDigit(long int x){
	int result=0;
	while(x>0){
		result=result+1;
		x = x/10;
	}
	return result;
}

long int mypow10(int n){
	long int result;
	if (n == 0) return 1;
	if (n == 1) return 10;
	else {
		result = mypow10(n/2);
		result = result * result;
		if (n % 2 == 0) return result;
		else return result*10;
	}
}

int kaprekar(long int x){
	long int square;
	long int nD;
	long int divider;
	long int lsb,msb;
	square = x*x;
	nD = nDigit(square);
	
	if (nD % 2 == 0){
		divider = mypow10(nD/2);
		lsb = square % divider;
		msb = square / divider;
		if ((lsb+msb == x)&&(lsb>0)) return 1;
		else return 0;
	}
	else{
		divider = mypow10((nD+1)/2);
		lsb = square % divider;
		msb = square / divider;
		if ((lsb+msb == x)&&(lsb>0)){
		 return 1;
		}
		
		divider = mypow10(nD/2);
		lsb = square % divider;
		msb = square / divider;
		if ((lsb+msb == x)&&(lsb>0)){
		 return 1;
		}		
		return 0;
	}
	return 0;
}

int main(){
	int nInput,nTest;
	int ll,rr,left,right;
	int i,j;
	int ka[MAX];
	int nAns;
	int ans[MAX];
	int xxx[] = {9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4879, 4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962};
	FILE *fp;
	
	if(DEBUG){
		fp = fopen("in.txt","r");
	}
	else{
		fp = stdin;
	}

	nAns = 0;
	/*
	for(i=2;i<MAX;i++){
		if(kaprekar(i)){
			ka[i] = 1;
			
		}
		else {
			ka[i]= 0;
		}
	}
	*/
	for(i=2;i<MAX;i++){
		ka[i] = 0;
	}
	for(i=0;i<19;i++){
		ka[xxx[i]] = 1;
	}
	fscanf(fp,"%d",&nInput);
	nTest = 1;
	while(nTest <= nInput){
		printf("case #%d\n",nTest);
		nTest++;
		
		/*fscanf(fp,"%d %d",&left,&right);*/		
		
		fscanf(fp,"%d %d",&ll,&rr);
		if(ll<rr){
			left = ll;
			right = rr;
		}
		else{
			left=rr;
			right=ll;
		}
		
		nAns=0;
		for(i=left;i<=right;i++){
			if(ka[i] == 1){
				ans[nAns] = i;
				nAns++;
			}
		}
		if(nAns == 0){
			printf("no kaprekar numbers\n");
		}
		else{
			for(i=0;i<nAns;i++){
				printf("%d\n",ans[i]);
			}
		}
		if(nTest <= nInput){
			printf("\n");
		}
	}
	
	
	if(DEBUG){
		printf("\n");
		for(i=0;i<MAX;i++){
			if(ka[i]==1){
				printf("%d \n",i);
			}
		}
	}
	return 0;
}