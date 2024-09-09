#include <stdio.h>
#define DEBUG 1

#define LEN 16
#define BIG_MONTH do { if (day > 31) return 0; } while(0);
#define SMALL_MONTH do { if (day > 30) return 0; } while(0);

char *szMonth[] = {"December",
			"January", "February", "March", "April", 
			"May", "June", "July", "August", 
			"September", "October", "November", "December"
};

char *szWeekday[] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
	"Friday", "Saturday", "Sunday"
};

int nDay[] = {
0, 31, 28, 31, 30, 31, 30, 
	31, 31, 30, 31, 30, 31};

const int startDay = 4;


int isLeapYear(int year){
	if(year % 4 != 0) return 0;
	
	if(year > 1752){	
		if(year % 100 == 0){
			if (year % 400 == 0) return 1;
			else return 0;
		} 
	}
	return 1;
}

int isValidDate(int month, int day, int year){
	if((month <= 0) || (day <= 0) || (year < 0)) return 0;
	
	if(month > 12) {
		return 0;
	}

	if((year == 1752) && (month == 9)){
		if(day <= 2) return 1;
		if((day > 2) && (day < 14)) return 0;
		if((day >= 14) && (day <= 30)) return 1;
		return 0;
	}	
	
	switch(month){
		case 2:
			if(day > 29) return 0;
			if(day == 29){
				if(isLeapYear(year)) return 1;
				else return 0;
			}
			return 1;
		default:
			if(day > nDay[month]) return 0;
			break;
	}
	return 1;
}

int calcLeapYearNum(int year){
	int result;
	result = year / 4;
	
	
	if(year > 1752){
		result = result - (year / 100) + (year / 400);
	}
	
	
	return result;
}

int main(){
	int day, month, year;
	int nLeapYear, wd;
	int daySum[13];
	int i, totalDay;
	FILE *fp;
	fp = (DEBUG)? fopen("in.txt", "r") : stdin;
	
	daySum[0] = 0;
	for(i=1; i<13;i++){
		daySum[i] = daySum[i-1] + nDay[i];
	}
	
	while(3 == fscanf(fp, "%d %d %d", &month, &day, &year)){
		if((month == 0) && (day == 0) && (year == 0)){
			break;
		}
		/*check if a valid date*/
		if(!isValidDate(month, day, year)){
			printf("%d/%d/%d is an invalid date.\n", month, day, year);
			continue;
		}
		
		nLeapYear = calcLeapYearNum(year);
		totalDay = year*365 + nLeapYear + daySum[month - 1] + day;
		if(isLeapYear(year)){
			totalDay--;
			if(month > 2){
				totalDay += 1;
			}
		} 
		wd = (totalDay + startDay) % 7;
		if(DEBUG){
			printf("totalDay=%d, wd=%d\n", totalDay, wd);
		}
		printf("%s %d, %d is a %s\n", szMonth[month], day, year, szWeekday[wd]);
		 
	}
	return 0;
}