#include <stdio.h>
#include <stdlib.h>

int compareInt(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int main(){
	int s[3];
	while(3 == scanf("%d %d %d", s, s+1, s+2)){
		if((s[0] == 0) && (s[1] == 0) && (s[2] == 0)){
			break;
		}
		qsort(s, 3, sizeof(int), compareInt);
		if(s[0]*s[0] + s[1]*s[1] == s[2]*s[2]){
			printf("right\n");
		}
		else{
			printf("wrong\n");
		}
	}
	return 0;
}