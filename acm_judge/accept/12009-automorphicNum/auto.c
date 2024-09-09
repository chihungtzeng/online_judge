/*OK!*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 512
 
char *generator = "66323172405515756102352543994999345608083801190741530060056055744818709692785099775918050075416428527708162011350246806058163276171676765260937528056844214486193960499834472806721906670417240094234466197812426690787535944616698508064636137166384049029219341881909581659524477861846140912878298438431703248173428886572737663146519104988029447960814673760503957196893714671801375619055462996814764263903953007319108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625";
const size_t gLen = 500;

char *aNum[2];
 
int isValidNumber(char *num, short k){
	if(strlen(num) == k) return EXIT_SUCCESS;
	else return EXIT_FAILURE;	
}
	

void findBuddy(char *src, char *target, short k){
	/*target = 10^k + 1 - src*/
	short i;
	char carry = 9 + '0';
	for(i=0; i<k; i++){
		target[i] = carry - src[i];
	}
	
	carry = 2;
	for(i=k-1; i>=0; --i){
		target[i] += carry;
		carry = target[i] / 10;
		target[i] = (target[i] % 10) + '0';  
	}
	target[k] = '\0';
}	

int generateAutoMorphicNum(short k){
	char *tmp, i;
	strcpy(aNum[0], generator + gLen - k);
	findBuddy(aNum[0], aNum[1], k);
	if(strncmp(aNum[0], aNum[1], k) > 0){
		tmp = aNum[0];
		aNum[0] = aNum[1];
		aNum[1] = tmp;
	}
	for(i=0; i<2; ++i){
		if(aNum[i][0] != '0'){
			printf(" %s", aNum[i]);
		}
	}
	printf("\n");
	return 0;
}
	
int main(){
	short i, k, nTest, kase = 1;
	for(i=0; i<2; i++){
		aNum[i] = (char *) malloc(sizeof(char)*LEN);
	}

	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%hd", &k);
		if(k == 1){
			printf("Case #%hd: 0 1 5 6\n", kase++);
		}
		else {
			printf("Case #%hd:", kase++);
			generateAutoMorphicNum(k);
		}
	}	
	
	for(i=0; i<2; i++){
		free(aNum[i]);
	}
	return 0;
}
