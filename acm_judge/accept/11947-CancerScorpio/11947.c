#include <stdio.h>
#include <time.h>
#include <string.h>
#define LEN 16
#define PREGANT_PERIOD 24192000

short nTest, kase = 1;

/*void parseDate(struct tm *date, char line[], char cDay[], char cMonth[], char cYear[]){*/
void decidePregantDate(struct tm *date, char line[]){
	char sdate[LEN];
	memset(sdate, 0, LEN);

	strncat(sdate, line + 4, 4);
	strcat(sdate, ":");
	strncat(sdate, line, 2);
	strcat(sdate, ":");
	strncat(sdate, line + 2, 2);
	/*printf("sdate=%s\n", sdate);*/

	memset(date, 0, sizeof(struct tm));
	strptime(sdate, "%Y:%m:%d", date);
	/*printf("%s\n", asctime(date));*/
}

void decideZodiac(short month, short day, char zodiac[]){
	if((month == 1) && (day < 21)) strcpy(zodiac, "capricorn");

	else if((month == 1) && (day >= 21)) strcpy(zodiac, "aquarius");
	else if((month == 2) && (day < 20)) strcpy(zodiac, "aquarius");	

	else if((month == 2) && (day >= 20)) strcpy(zodiac, "pisces");
	else if((month == 3) && (day < 21)) strcpy(zodiac, "pisces");	

	else if((month == 3) && (day >= 21)) strcpy(zodiac, "aries");
	else if((month == 4) && (day < 21)) strcpy(zodiac, "aries");
	
	else if((month == 4) && (day >= 21)) strcpy(zodiac, "taurus");
	else if((month == 5) && (day < 22)) strcpy(zodiac, "taurus");

	else if((month == 5) && (day >= 22)) strcpy(zodiac, "gemini");
	else if((month == 6) && (day < 22)) strcpy(zodiac, "gemini");

	else if((month == 6) && (day >= 22)) strcpy(zodiac, "cancer");
	else if((month == 7) && (day < 23)) strcpy(zodiac, "cancer");
	
	else if((month == 7) && (day >= 23)) strcpy(zodiac, "leo");
	else if((month == 8) && (day < 22)) strcpy(zodiac, "leo");
	
	else if((month == 8) && (day >= 22)) strcpy(zodiac, "virgo");	
	else if((month == 9) && (day < 24)) strcpy(zodiac, "virgo");
	
	else if((month == 9) && (day >= 24)) strcpy(zodiac, "libra");
	else if((month == 10) && (day < 24)) strcpy(zodiac, "libra");
		
	else if((month == 10) && (day >= 24)) strcpy(zodiac, "scorpio");	
	else if((month == 11) && (day < 23)) strcpy(zodiac, "scorpio");
	
	else if((month == 11) && (day >= 23)) strcpy(zodiac, "sagittarius");
	else if((month == 12) && (day < 23)) strcpy(zodiac, "sagittarius");
	else strcpy(zodiac, "capricorn");
}

void solve(struct tm *birthDate){
	char cMonth[3], cDay[3], cYear[5], zodiac[LEN];
	short month, day, year;
	strftime(cMonth, 3, "%m", birthDate);	
	strftime(cDay, 3, "%d", birthDate);
	strftime(cYear, 5, "%Y", birthDate);
	month = atoi(cMonth);
	day = atoi(cDay);	
	year = atoi(cYear);

	decideZodiac(month, day, zodiac);	
	
	printf("%hd %02hd/%02hd/%04hd %s\n", kase++, month, day, year, zodiac);
	
}

int main(){
	struct tm pregantDate, birthDate;
	time_t birthTime;
	
	char line[LEN];
	
	FILE *fp = stdin;
	
	scanf("%hd", &nTest);
	while(nTest > 0){
		nTest--;
		scanf("%s", line);
		decidePregantDate(&pregantDate, line);	
		birthTime = mktime(&pregantDate) + PREGANT_PERIOD;
		localtime_r(&birthTime, &birthDate);
		solve(&birthDate);

	}
	return 0;
}