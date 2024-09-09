#include <stdio.h>


int main(){
	int nDish;
	int top, bottom, dish;
	int ans, i;
	
	while(1 == scanf("%d", &nDish)){
		if(0 == nDish) break;
		scanf("%d", &top);
		ans = 1;
		bottom = top;
		for(i=1; i<nDish; i++){
			scanf("%d", &dish);
			if(dish <= top) {
				ans++;
				top = dish;
			} else if (dish >= bottom){
				ans++;
				bottom = dish;
			} 
		}
		printf("%d\n", ans);
	}
	return 0;
}