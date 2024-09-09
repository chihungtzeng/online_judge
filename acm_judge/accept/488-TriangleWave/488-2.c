/*try low level IO*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 32000000

int main(){
	short height, amplitude, first, flag;
	int nTest, freq;
	int i,j;
	char *s;
	size_t slen;
	
	scanf("%d", &nTest);
	first = 1;
	s = (char *) malloc(sizeof(char)*MAX);
	while(nTest >= 1){
		slen = 0;
		if(!first){
			s[slen++] = '\n';
		}
		else {
			first = 0;
		}
		
		scanf("%hd %d", &amplitude, &freq);
		flag = 1;
		for(i=0; i<freq; i++){
			if(!flag){ 
				s[slen++] = '\n';
			}
			else{
				flag = 0;
			}
			
			for(height = 1; height<=amplitude; height++){
				for(j=1; j<=height;j++){
					s[slen++] = height + '0';
					
				}
				s[slen++] = '\n';

			}
			for(height = amplitude - 1; height > 0; height--){
				for(j=1; j<=height;j++){
					s[slen++] = height + '0';
				}
				s[slen++] = '\n';
			}
		}
		write(1, s, slen);
		nTest--;
	}	
	free(s);	
	return 0;
}