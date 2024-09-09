#include <stdio.h>
#include <string.h>
#define MAX 1005

int main(){
	short dsum, len, i;
	char num[MAX];

	while(1){
		scanf("%s", num);
		if((num[0] == '0') && (num[1] == '\0')){
			break;
		}
		len = strlen(num);
		dsum = 0;
		for(i=0; i<len; i++){
			if(i % 2 == 0){
				dsum = dsum + num[i] - '0';
			}
			else {
				dsum = dsum - (num[i] - '0');
			}
		}
		if(dsum % 11 == 0){
			printf("%s is a multiple of 11.\n", num);
		}
		else{
			printf("%s is not a multiple of 11.\n",num);
		}
	}	
	
	return 0;
}