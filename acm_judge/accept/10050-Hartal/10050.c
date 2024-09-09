#include <stdio.h>
#include <string.h>
#define MAX 3650

int main(){
	char hartal[MAX], done;
	short nHartal, nParty, nDay;
	short hartalFreq[100];
	short nTest;
	short i, j, k;
	scanf("%hd",&nTest);
	while(nTest >= 1){
		nTest--;
		scanf("%hd %hd",&nDay, &nParty);
		for(i=nParty - 1; i>=0; i--){
			scanf("%hd", hartalFreq + i);
		}
		
		memset(hartal, 0, MAX);
		for(i=0; i<nParty; i++){
			done = 0;
			for(j=1; !done ; j++){
				k = j * hartalFreq[i] - 1;
				if(k >= nDay){
					done = 1;
					continue;
				}
				else{
					if((k % 7 != 5) && (k % 7 != 6)){
						hartal[k] = 1;
					}
				}
			}
		}
		nHartal = 0;
		for(i=0; i<nDay; i++){
			nHartal += hartal[i];
		}
		printf("%hd\n",nHartal);
	}	
	
	return 0;
}