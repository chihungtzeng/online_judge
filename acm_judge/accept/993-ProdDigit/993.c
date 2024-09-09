#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define DEBUG 1

struct hashEntry {
	int key;
	int value;
};

char *itoa(int n){
	char *s;
	char c;
	int len=0,i;
	s = (char *) malloc(sizeof(char)*20);
	while(n>0){
		s[len] = (n % 10) +'0';
		len++;
		n = n/10;
	}
	for(i=0;i<len/2;i++){
		c = s[i];
		s[i] = s[len - 1 -i];
		s[len -1 -i] = c;
	}
	s[len] = '\0';
	return s;
}

int compareHashEntry(const void *x, const void *y){
/*sort by key value*/
	struct hashEntry a,b;
	a = *(struct hashEntry *)x;
	b = *(struct hashEntry *)y;
	if( a.key > b.key) return 1;
	if( a.key < b.key) return -1;
	return 0;
}

int compareChar(const void *x, const void *y){
	char a,b;
	a = *(char *)x;
	b = *(char *)y;
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}

int isIncreasing(char *s){
/*return 1 if s is monotonically increasing
"11234" -> return 1
"107234" -> return 0
*/
	int i,len;
	len =strlen(s);
	for(i=0;i<len-1;i++){
		if(s[i] > s[i+1]){
			return 0;
		}
	}
	return 1;
}

int containsZero(char *s){
	/*return 1 if s contains '0'*/
	int i, len;
	len =strlen(s);
	for(i=0;i<len;i++){
		if ('0' == s[i]){
			return 1;
		}
	}
	return 0;
}

void shrinkString(char *s){
	/*remove 1s from s*/
	int len,i,j;
	len = strlen(s);
	i=0;
	j=0;
	while('\0' != s[i]){
		if('1' != s[i]){
			s[j] = s[i];
			j++;
			i++;
		} 
		else {
			i++;
		}
	}
	s[j] = '\0';
}

int dProdt_byString(char *s){
	int len,i,j;
	int result;
	len = strlen(s);
	if (s[0] == '0') return 0;
	i=0;
	while((s[i] == '1') && (i<len)){
		i++;
	}
	result = 1;
	for(j=i;j<len;j++){
		result = result * (s[j] - '0');
	}
	
	return result;
}

int main(){
	int nInput;
	int input;
	char *s;
	long int i,v;
	long int nEntry;
	struct hashEntry *hashtable;
	struct hashEntry *ans,target;
	FILE *fp;
	
	hashtable = (struct hashEntry *) malloc(sizeof(struct hashEntry)*MAX);
	if(hashtable == NULL){
		printf("init hashtable error\n");
	} 
	fp = stdin;
	nEntry = 0;
	for(i=1;i<MAX;i++){
		s = itoa(i);
		
		/*
		a number contains 0 always maps to 0 -> don't care
		
		a number whose digits are not incresing has been calculated -> don't care
		that is, "123" and "132" map to the same value
		*/
		if(containsZero(s) || !isIncreasing(s)){
			
			continue;
		}
		
		//shrinkString(s);
		v = dProdt_byString(s);

		hashtable[nEntry].value = i;		
		hashtable[nEntry].key = v;
		nEntry++;		
		
		
	}
	if(DEBUG){
			printf("nEntry=%ld, value=%ld key=%ld\n",nEntry,i,v);
			for(i=0;i<nEntry;i++){
				printf("(%d %d) ", hashtable[i].key,hashtable[i].value);
			}
	}	
	
	qsort(hashtable,nEntry-1,sizeof(struct hashEntry),compareHashEntry);
	
	fscanf(fp,"%d",&nInput);
	for(i=0;i<nInput;i++){		
		fscanf(fp,"%d",&input);
		ans = NULL;
		target.key = input;
		ans = bsearch(&target,hashtable,nEntry-1,sizeof(struct hashEntry),compareHashEntry);
		if(ans == NULL){
			printf("-1\n");
		}
		else{
			printf("%d\n",ans->value);
		}
		
	}

	return 0;
}
