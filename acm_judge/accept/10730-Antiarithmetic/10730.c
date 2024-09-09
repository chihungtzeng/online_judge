#include <stdio.h>
#define MAX 10010

short n, input[MAX], pos[MAX];

short isAntiarithmetic(){
	short i, j;
	short target;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			target = input[j] + input[j] - input[i];
			if((target >= 0) && (target < n) && (pos[target] > j)){
				return 0;
			}  
		}
	}
	return 1;
}


int main(){
	short i;
	char delim;

	while(1 == scanf("%hd", &n)){
		if(n == 0) break;
		scanf("%c", &delim);
		
		for(i=0; i<n; i++){
			scanf("%hd", &input[i]);
			pos[input[i]] = i;
		}
		if(isAntiarithmetic()){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}		
	}
	
	return 0;
}