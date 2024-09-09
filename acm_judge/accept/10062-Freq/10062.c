#include <stdio.h>
#include <string.h>
#define MAXN 32000
#define START 32
#define END 128

struct ascfreq{
	int code;
	int freq;
};

int compareFreq(const void *a, const void *b){
	struct ascfreq x, y;
	x = *(struct ascfreq *)a;
	y = *(struct ascfreq *)b;
	return (x.freq - y.freq)*256 + (y.code - x.code); 
}

int main(){
	struct ascfreq frequency[END];
	char line[MAXN];
	FILE *fp;
	short first = 1;
	short code;
	int i;
	char ch;
	
	fp = stdin;
	while(NULL != (fgets(line,MAXN,fp))){
		
		if(!first){
			printf("\n");
		}
		else{
			first = 0;
		}
		
		memset(frequency, 0, sizeof(struct ascfreq)*END);
		
		for(i=32; i < END; i++){
			frequency[i].code = i;
		}
		ch = line[0];
		i = 0;
		while ( (ch != '\0') && ( ch != '\n')){
			frequency[(int)ch].freq += 1;
			i++;
			ch = line[i];
		}
		
		qsort(frequency+START, END - START, sizeof(struct ascfreq),compareFreq);

		
		for(i = START; i < END; i++){
			if(frequency[i].freq != 0){
				printf("%d %d\n", frequency[i].code, frequency[i].freq);
			}
		}
	}
	 
}