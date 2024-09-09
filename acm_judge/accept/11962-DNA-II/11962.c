#include <stdio.h>
#include <string.h>
#define MAX 30

long long pow3[MAX];
char map[256];

long long getIndex(char dna[], size_t len){
	short i;
	long long sum = 0;
	for(i=0; i<len; i++){
		sum += map[dna[i]] * pow3[len - i - 1];
	}
	return sum;
}

int main(){
	size_t len;
	short nTest, k = 1;
	char dna[MAX + 1];
	map['A'] = 0;
	map['C'] = 1;
	map['G'] = 2;
	map['T'] = 3;
	
	pow3[0] = 1;
	for(len = 1; len < MAX; len++){
		pow3[len] = pow3[len - 1] << 2;
	}
	
	scanf("%hd", &nTest);
	while(nTest > 0){
		nTest--;
		scanf("%s", dna);
		len = strlen(dna);
		printf("Case %hd: (%ld:%lld)\n", k++, len, getIndex(dna, len));
	}
	return 0;
}