#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum color {B,G,C};

int main(){
	long int bottle[3][3];
	long int total;
	int i,j;
	enum color x,y,z;
	long int sum,tmp; 
	char *ans;
	ans = (char *) malloc(sizeof(char)*4);
	
	while(3 == scanf("%ld %ld %ld",&bottle[0][0],&bottle[0][1],&bottle[0][2])){
		scanf("%ld %ld %ld",&bottle[1][0],&bottle[1][1],&bottle[1][2]);
		scanf("%ld %ld %ld",&bottle[2][0],&bottle[2][1],&bottle[2][2]);
		total = 0;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				total += bottle[i][j];
			}
		}
		/*BCG*/
		x = B; y = C; z = G;
		sum = total - bottle[0][x] - bottle[1][y] - bottle[2][z];
		strcpy(ans,"BCG");
		/*BGC*/
		x = B; y = G; z = C;
		tmp = total - bottle[0][x] - bottle[1][y] - bottle[2][z];
		if(tmp < sum){
			sum = tmp;
			strcpy(ans,"BGC");
		}
		/*CBG*/
		x = C; y = B; z = G;
		tmp = total - bottle[0][x] - bottle[1][y] - bottle[2][z];
		if(tmp < sum){
			sum = tmp;
			strcpy(ans,"CBG");
		}
		/*CGB*/
		x = C; y = G; z = B;
		tmp = total - bottle[0][x] - bottle[1][y] - bottle[2][z];
		if(tmp < sum){
			sum = tmp;
			strcpy(ans,"CGB");
		}
		/*GBC*/
		x = G; y = B; z = C;
		tmp = total - bottle[0][x] - bottle[1][y] - bottle[2][z];
		if(tmp < sum){
			sum = tmp;
			strcpy(ans,"GBC");
		}
		/*GCB*/
		x = G; y = C; z = B;
		tmp = total - bottle[0][x] - bottle[1][y] - bottle[2][z];
		if(tmp < sum){
			sum = tmp;
			strcpy(ans,"GCB");
		}
		printf("%s %ld\n",ans,sum);
	} 
	free(ans);
	return 0;
	
}