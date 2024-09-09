#include <stdio.h>
#include <stdlib.h>
#define MAX 101

int gcd(int a, int b){
	if (b == 0) return a;
	else return gcd(b, a%b);
}

void showFraction(int up, int down){
	int ident;
	int a, b, c, g;
	int aup;
	int downlen;
	char sdown[20];
	char sup[20];
	char sa[20];
	int i;
	/*if up/down is an integer*/
	aup = abs(up);
	if( aup % down == 0){
		if(up < 0){
			printf("- %d\n", aup / down);
		} else {
			printf("%d\n", aup / down);
		}
		return ;
	}	
	ident = (up < 0)? 2 : 0;
	
	a = aup / down;
	b = aup % down;
	g = gcd(b , down);
	b = b / g;
	down = down / g;
	downlen = sprintf(sdown, "%d", down);
	if(a > 0){
		ident += sprintf(sa, "%d", a);
	}
	printf("%*d\n", downlen + ident, b);
	if(up < 0) {
		printf("- ");
	}
	if(a > 0){
		printf("%s", sa);
	}
	for(i=0; i<downlen; i++){
		printf("%c", '-');
	}
	printf("\n");
	printf("%*s\n", ident + downlen, sdown);
} 


int main(){
	int nNum, k=1;
	int num[MAX];
	int sum;
	int i;
	int g;
	int a, b, c;
	while(1 == scanf("%d", &nNum)){
		if(0 == nNum){
			break;
		}
		sum = 0;
		for(i=0; i<nNum; i++){
			scanf("%d", num + i);
			sum += num[i];
		}
		printf("Case %d:\n", k++);
		showFraction(sum, nNum);
	}
	
	return 0;
}