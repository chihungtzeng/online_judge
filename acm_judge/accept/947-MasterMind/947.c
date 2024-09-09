#include <stdio.h>
#include <string.h>
#define MATCH 1
#define YES 1
#define NO 0
#define DEBUG 0

short nRightPlace; 
short nWrongPlace;
int guess;

int containZero(int n){
	while(n > 0){
		if(n % 10 == 0) return YES;
		n = n/10;
	}
	return NO;
}

int check(int x, int y){
	int r=0, w=0;
	short xDigit[5], yDigit[5],mark[5];
	short nDigit = 0, i, j;
	short xd, yd, match;
	
	while(x > 0){
		xd = x % 10;
		yd = y % 10;
		if(xd == yd){
			r++;
		}
		else{
			xDigit[nDigit] = xd;
			yDigit[nDigit] = yd;
			nDigit++;
		}
		x = x / 10;
		y = y / 10;
	}
	if(r != nRightPlace){
		return NO;
	}
	memset(mark, 0, sizeof(short)*5);
	for(i=0; i<nDigit; i++){
		match = 0;
		for(j=0; (j<nDigit) && (!match);j++){
			if((xDigit[i] == yDigit[j]) && (mark[j] == 0)){
				match = 1;
				mark[j] = 1;
			}
		}
		if(match){
			w++;
		}
	}
	if(w == nWrongPlace){
		return YES;
	}	
	else{
		return NO;
	}
}

int main(){
	int secret;
	int i,j, nTest, start, end;
	short len;
	char guessStr[6];
	int count;
		
	scanf("%d", &nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%s %hd %hd", guessStr, &nRightPlace, &nWrongPlace);
		guess = atoi(guessStr);
		len = strlen(guessStr);
		start = 1;
		end = 9;
		for(i=1;i<len;i++){
			start = start*10 + 1;
			end = end*10 + 9;
		}
		count = 0;
		if(DEBUG){
			printf("start=%d end=%d guess:%s, nR:%hd, nW:%hd\n",start,end,guessStr, nRightPlace, nWrongPlace);
		}
		for(secret = start; secret <= end; secret++){
			if( (check(guess, secret)) && (!containZero(secret))){
				count++;
			} 
		}
		printf("%d\n",count);
	}
	return 0;
}