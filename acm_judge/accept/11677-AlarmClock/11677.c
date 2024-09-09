#include <stdio.h>

int main(){
	short h1, m1, h2, m2;
	int start, end;
	while(4 == scanf("%hd %hd %hd %hd", &h1, &m1, &h2, &m2)){
		if((h1 == 0) && (m1 == 0) && (h2 == 0) && (m2 == 0)){
			break;
		}
		start = h1*60 + m1;
		end = h2*60 + m2;
		if(end < start){
			end += 24*60;
		}
		printf("%d\n", end-start);
	}
	return 0;
}