#include <stdio.h>
#include <string.h>
#define MAX 64

short nDigit(int n){
	int pos;
	short nD=0;
	while(n > 0){
		pos = ffs(n);
		nD++;
		n = n >> pos;
	}
	return nD;
}

void toBitSeq(int x, char *s){
	short len = 0, i, j;
	while(x > 0){
		s[len] = (x & 1) + '0';
		len++;
		x = x >> 1; 
	}
	for(i= len/2 - 1; i>=0; i--){
		j = len - i - 1;
		s[i] = s[i] ^ s[j];
		s[j] = s[i] ^ s[j];
		s[i] = s[i] ^ s[j];
	}
	s[len] = '\0';
}

int main(){
	int x;
	short nD, i;
	char bitSeq[MAX];
	while(1){
		scanf("%d",&x);
		if(0 == x){
			break;
		}
		toBitSeq(x, bitSeq);
		nD = nDigit(x);
		printf("The parity of %s is %d (mod 2).\n", bitSeq, nD);
	}
	return 0;
}