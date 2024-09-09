#include <stdio.h>
#include <string.h>
#define LEN 64

char charMap[255];
char input[LEN], output[LEN];

int calcMinBase(char input[]){
	char *p;
	int result = -1;
	p = input;
	while(*p != '\0'){
		if(charMap[*p] > result) result = charMap[*p];
		p++;
	}
	return result + 1;
}

void convertBase(int targetBase, char *output, int srcBase, char *input){
	char *p, *head;
	long long n = 0;
	int r;
	/*atoi*/
	p = input;
	while(*p != '\0'){
		n = n*srcBase + charMap[*p];
		p++;
	}
	p = output;
	
	while(n > 0){
		r = n % targetBase;
		n = n / targetBase;
		*p = (r < 10)? r + '0' : r - 10 + 'A';
		p++;
	}
	*p = '\0';
	p--;
	head = output;
	while(head < p){
		*head = (*p) ^ (*head);
		*p = (*p) ^ (*head);
		*head = (*p) ^ (*head);
		p--;
		head++;
	}
	if(output[0] == '\0'){
		output[0] = '0';
		output[1] = '\0';
	}
}

int main(){
	char i;
	int srcBase, targetBase, minBase;
	
	for(i='0'; i<='9'; i++){
		charMap[i] = i - '0';
	}
	for(i='A'; i<='F'; i++){
		charMap[i] = i - 'A' + 10;
	}
	while(3 == scanf("%d %d %s", &srcBase, &targetBase, input)){
		minBase = calcMinBase(input);
		if(minBase > srcBase){
			printf("%s is an illegal base %d number\n", input, srcBase);
		} else {
			
			convertBase(targetBase, output,srcBase, input);
			printf("%s base %d = %s base %d\n", input, srcBase, output, targetBase); 
		}
	}
	return 0;
}