#include <stdio.h>
#define MAX 101

int main(){
	int ans[MAX];
	int i;
	
	ans[0] = 0;
	for(i=1; i<MAX; i++){
		ans[i] = ans[i-1] + i*i;
		#if 0
		printf("ans[%d] = %d\n", i, ans[i]);
		#endif
	}

		
	
	while(1 == scanf("%d", &i)){
		if(i == 0) break;
		else printf("%d\n", ans[i]);
	}
	
	return 0;
}