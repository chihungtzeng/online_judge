#include <stdio.h>

int main(){
	short nBottle, ans, tmp;
	while(1 == scanf("%hd",&nBottle)){
		if(0 == nBottle){
			break;
		}
		ans = 0;
		while(nBottle >= 3){
			tmp = nBottle / 3;
			ans += tmp;
			nBottle = (nBottle % 3) + tmp;
		}
		if(nBottle == 2){
			ans++;
		}
		printf("%hd\n",ans);
	}
	return 0;
}