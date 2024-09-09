#include <stdio.h>

int main(){
	int B,S;
	int k=1;
	while(2 == scanf("%d %d", &B, &S)){
		if((0 == B) && (0 == S)) break;
		if(B > 1){
			if(S >= B){
				printf("Case %d: :-|\n",k++);
			} else {
				printf("Case %d: :-(\n",k++);
			}
		} else if (B == 1){
			printf("Case %d: :-\\\n",k++);
		}
	}
	return 0;
}