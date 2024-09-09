#include <stdio.h>

int main(){
	short N, mark, i, nAns;
	char sAns;
	
	
	while(1 == scanf("%hd", &N)){
		
		if(0 == N){
			break;
		}
		while(N >= 1){
			N--;
			nAns = 0;
			for(i=0; i<5; i++){
				scanf("%hd", &mark);
				
				if(mark <= 127){
					nAns++;
					sAns = i + 'A';
				}
			}
			
			if(nAns == 1){
				printf("%c\n", sAns);
			}
			else{
				printf("*\n");
			}
		}
	}
	return 0;
}