/*AC*/
/*
	Catalan Number
	s[0] = 1,
	for i>=1, s[i] = sum {s[j]*s[i-j-1]}, where j=0,..,i-1
*/
#include <stdio.h>
int main(){
	int s[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796};
	int i;
	int first = 1;

	
	while(1 == scanf("%d",&i)){
		if(!first){
			puts("");
		}
		else{
			first = 0;
		}
		printf("%d\n",s[i]);
	}
	return 0;
}