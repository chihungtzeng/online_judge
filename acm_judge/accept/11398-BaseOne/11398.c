#include <stdio.h>
#include <string.h>
#define LEN 31

int main(){

	char len, len_2, flag = 0;
	char tok[LEN];
	int n = 0;
		
	while(1){
		scanf("%s", tok);
		if(tok[0] == '0'){
			len = strlen(tok);
			if(len == 1) flag = 1;
			else if (len == 2) flag = 0;
			else {
				while(len > 2){
					len--;
					n = (n << 1) | flag;
				}
			}  
		}
		else if(tok[0] == '#'){
			printf("%d\n",n);
			n = 0;
		} else if(tok[0] == '~'){
			break;
		}
	}
	return 0;
}