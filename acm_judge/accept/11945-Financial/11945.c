#include <stdio.h>
#define SWAP(a, b) (a) = (a) ^ (b); (b) = (a) ^ (b); (a) = (a) ^ (b)


void solve(double total, char k){
	char output[32];
	char tmp[32];
	char i, j, count;
	size_t len;	
	len = sprintf(output, "%.2lf", total);
	tmp[0] = output[len - 1];
	tmp[1] = output[len - 2];
	tmp[2] = '.';
	for(count = 0, i=len - 4, j = 3; i >= 0; i--){
		tmp[j++] = output[i];
		count++;
		if((count == 3) && (i != 0)){
			count = 0;
			tmp[j++] = ',';
		}
	}
	len = j;
	for(i=0; i<len; i++){
		output[i] = tmp[len - i - 1];
	}
	output[len] = '\0';
	printf("%hhd $%s\n", k, output);
}

int main(){
	char nTest, i;
	char k = 1;
	double total, money;
	scanf("%hhd", &nTest);
	while(nTest > 0){
		nTest--;
		total = 0;
		for(i=0; i<12; i++){
			scanf("%lf", &money);
			total += money;
		}
		total = total / 12;
		
		solve(total, k);
		k++;
	}
	return 0;
}