#include <stdio.h>
#include <time.h>
#define LEN 16

int main(){
	char month[4], day[4];
	char date[LEN];
	char output[LEN];
	short nTest;
	struct tm ctm;
	
	scanf("%hd", &nTest);
	while(nTest--){
		scanf("%s %s", month, day);
		sprintf(date, "%s-%s-%s", "2011", month, day);
		strptime(date, "%Y-%m-%d", &ctm);
		strftime(output, LEN, "%A", &ctm);
		puts(output);
	}
	return 0;
}