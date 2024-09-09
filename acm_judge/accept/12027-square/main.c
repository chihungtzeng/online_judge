#include <stdio.h>
#include <string.h>
#define MAX 1001

char input[MAX];
char output[MAX];

char findPrefix(short n){
	/* n is a 1-digit or 2-digit number*/
	if(n < 4) return 1;
	else if (n < 9) return 2;
	else if (n < 16) return 3;
	else if (n < 25) return 4;
	else if (n < 36) return 5;
	else if (n < 49) return 6;
	else if (n < 64) return 7;
	else if (n < 81) return 8;
	else return 9;
}

void solve(){
	short i, j;
	size_t len = strlen(input);
	char tmp[3];
	
	short n;
	n = (len & 1)? 1 : 2;
	for(i=0; i<n; i++){
		tmp[i] = input[i];
	}
	tmp[i] = '\0';
	n = atoi(tmp);
	/*printf("tmp =%s, n=%hd\n", tmp, n);*/
	output[0] = findPrefix(n) + '0';
	
	for(i = len - 2, j = 1; i>=1; i -= 2){
		output[j++] = '0';
	}
	output[j] = '\0';
	puts(output);
}

int main(){
	while(1 == scanf("%s", input)){
		if(input[0] == '0') return 0;
		else solve();
	}
	return 0;
}