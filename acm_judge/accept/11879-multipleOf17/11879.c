#include <stdio.h>
#include <string.h>



int main(){
	char s[300];
	int i, len, n, m, d, r;
	long int x;
		
	while(1){
		scanf("%s",s);
		if(!strcmp(s,"0")){
			break;
		}
		len = strlen(s);
		
		while((len >= 3)){
			d = s[len - 1] - '0';
			n = (s[len-3] - '0')*10 + (s[len-2] - '0');
			r = n - 5*d;
			while(r < 0){
				r += 34;
			}
			s[len - 1] = '\0';
			s[len - 2] = (r % 10)+'0';
			s[len - 3] = (r/10) + '0';
			len--;
		}
		x = atoi(s);
		if(x % 17 == 0){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}
