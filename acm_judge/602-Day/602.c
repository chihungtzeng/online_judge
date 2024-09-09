#include <stdio.h>
#include <time.h>
#define LEN 16

int main(){
	int day, month, year;
	char date[LEN];
	char sMonth[LEN], sWeekday[LEN];
	struct tm ctm;
	while(3 == scanf("%d %d %d", &month, &day, & year)){
		if(month == 0) break;
		sprintf(date, "%d-%d-%d", year, month, day);
		strptime(date, "%Y-%m-%d", &ctm);
		strftime(sMonth, LEN, "%B", &ctm);
		strftime(sWeekday, LEN, "%A", &ctm);
		printf("%s %d, %d is a %s\n", sMonth, day, year, sWeekday);
		
	}
	return 0;
}