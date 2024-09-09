#include <stdio.h>

enum{
	TERM1,
	TERM2,
	FINAL,
	ATTENDANCE,
	TEST1,
	TEST2,
	TEST3,
	nSCORE
};

int score[7];

int MIN(int a, int b){
	if (a < b) return a;
	else return b;
}

char decideGrade(int grade){
	if(grade >= 90) return 'A';
	else if (grade >= 80) return 'B';
	else if (grade >= 70) return 'C';
	else if (grade >= 60) return 'D';
	else return 'F'; 
}


int calcGrade(){
	int sum = 0, i, min;
	min = MIN(MIN(score[TEST1], score[TEST2]), score[TEST3]);
	
	for(i=4; i<7; i++){
		sum += score[i];
	}
	sum = (sum - min) >> 1;
	for(i=0; i<4; i++){
		sum += score[i];
	}
	/*printf("min=%d, sum=%d\n", min, sum);*/
	return sum;
} 

int main(){
	int nTest, k=1, i;
	scanf("%d", &nTest);
	while(nTest--){
		for(i=0; i<7; i++){
			scanf("%d", score + i);
		}
		printf("Case %d: %c\n", k++,decideGrade(calcGrade()));
	}
	return 0;
}