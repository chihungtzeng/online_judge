#include <stdio.h>
#include <string.h>
#define MAX 128

int main(){
	int age[MAX];
	int i, n, input;
	int first; 
	while(1 == scanf("%d",&n)){
		if(0 == n) break;
		memset(age, 0, sizeof(int)*MAX);
		while(n >= 1){
			n--;
			scanf("%d", &input);
			age[input] += 1;
		}
		
		first = 0;
		while(age[first] == 0){
			first++;
		}
		printf("%d", first);
		age[first] -= 1;
		
		for(i=first; i<MAX; i++){
			while(age[i] >= 1){
				age[i] -= 1;
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}