#include <stdio.h>
#define MAX 10000000
#define LEN 2000001

int main(){
	int min, drug, burger;
	int L;
	char line[LEN];
	int pos, i;
	while(1){
		scanf("%d", &L);
		if(0 == L){
			break;
		}
		scanf("%s",line);
		min = MAX;
		drug = -1;
		burger = -1;
		for(pos=0; pos<L; pos++){
			if(line[pos] == 'D'){
				if((burger >= 0) && (pos - burger < min)){
					min = pos - burger;
				}
				drug = pos;
			}
			else if(line[pos] == 'R'){
				if((drug >= 0) && (pos - drug < min)){
					min = pos - drug;
				}
				burger = pos;
			}
			else if(line[pos] == 'Z'){
				min = 0;
				break;
			}
		}
		printf("%d\n", min);
	}
	return 0;
}