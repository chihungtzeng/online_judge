#include <stdio.h>
#include <string.h>
#define MAX 201

int main(){
	char input[MAX];
	int len,i;
	int sum, apple;
	
	while((1 == scanf("%s",input)) && (strcmp(input,"0"))){
		len = strlen(input);
		sum = 0;
		for(i= 0; i< len;i++){
			sum += input[i] - '0';
		}
		
		while(sum >= 10){
			apple = sum;
			sum  =0 ;
			while(apple > 0){
				sum += apple % 10;
				apple = apple / 10;
			}
			
		}
		printf("%d\n",sum);
	}
	return 0;
}