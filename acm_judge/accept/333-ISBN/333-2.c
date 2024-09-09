#include <stdio.h>
#include <string.h>
#define LEN 81
#define TRUE 1
#define FALSE 0
#define DEBUG 0

char hashValue[255];


int chomp(char ISBN[], char line[]){
	char *p;
	int len = 0;
	
	p = line;
	
	while(*p != '\0'){
		if(isdigit(*p)){
				ISBN[len++] = *p;
		} else if ((*p == 'X') && (len == 9)){
			ISBN[len++] = *p;
		/*} else if ((*p == 'X') && (len != 9)){*/
		}  else {
			return -1;
		}
		
		p++;
	}
	return len;
}

int legalISBN(char ISBN[]){
	int s[10];
	int i, sum;
	s[0] = hashValue[ISBN[0]];
	for(i=1; i<10; i++){
		s[i] = s[i-1] + hashValue[ISBN[i]];
	}
	for(i=0, sum = 0; i<10; i++){
		sum += s[i]; 
	}
	#if 0
	printf("sum=%d\n", sum);
	#endif
	return (sum % 11 == 0)? TRUE : FALSE;
}

int main(){
	char line[LEN], buf[LEN];
	char ISBN[LEN];
	char *ptr, *cur, *head, *tail;
	int linelen;
	FILE *fp;
	
	fp = (DEBUG)? fopen("in4.txt", "r") : stdin;
	int nDigit, i;

	for(i='0'; i<='9'; i++){
		hashValue[i] = i - '0';
	}
	hashValue['X'] = 10;
	
	while(NULL != fgets(line, LEN, fp)){
	
		
		head = line;
		while((*head == ' ') && (*head != '\0')) head++;
		if(*head != '\0'){
			tail = head;
			while(*tail != '\0'){
				if(isalnum(*tail) || (*tail == '-')){
					tail++;
				} else {
					*tail = '\0';
				}
			}
		}
		
		ptr = head;
		cur = buf;
		while(*ptr != '\0'){
			if(isdigit(*ptr) || (*ptr == 'X')){
				*cur = *ptr;
				cur++;
			}
			ptr++;
		}
		
		*cur = '\0';
		nDigit = chomp(ISBN, buf);
		#if 0
			printf("nDigit=%d buf=%s ISBN=%s\n", nDigit, buf, ISBN);
		#endif
		if((nDigit == 10) && (legalISBN(ISBN) == TRUE)) {
			printf("%s is correct.\n", head);
		} else {
			printf("%s is incorrect.\n", head);
		} 
	}
	return 0;
}