#include <stdio.h>

int main(){
	short nQuery, xDP, yDP, x, y;
	short i;
	while(1 == scanf("%hd",&nQuery)){
		if(0 == nQuery) return 0;
		
		scanf("%hd %hd", &xDP, &yDP);
		for(i = nQuery - 1; i >= 0; i--){
			scanf("%hd %hd",&x, &y);
			if((x == xDP) || (y == yDP)){
				puts("divisa");
			}
			else if ((x > xDP) && (y > yDP)){
				puts("NE");
			}
			else if ((x > xDP) && (y < yDP)){
				puts("SE");
			}
			else if ((x < xDP) && (y > yDP)){
				puts("NO");
			}
			else if ((x < xDP) && (y < yDP)){
				puts("SO");
			}
		}
	}
	return 0;
}