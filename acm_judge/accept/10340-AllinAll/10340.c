#include <stdio.h>
#include <stdlib.h>
#define LEN 8000000

char s[LEN], t[LEN];

void solve(){
	char *x, *y;
	x = s; 
	y = t;
	while((*x != '\0') && (*y != '\0')){
		if(*x == *y){
			x++;
			y++;
		}
		else{
			y++;
		}
	}
	if(*x == '\0'){
		puts("Yes");
	}
	else{
		puts("No");
	}
}

int main(){
	while(2 == scanf("%s %s", s, t)){
		solve();
	}
	return 0;
}