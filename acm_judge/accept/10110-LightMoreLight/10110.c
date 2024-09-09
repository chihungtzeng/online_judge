#include <stdio.h>
#include <math.h>
int main(){
	unsigned int num,sq;
	char buf[10240];	
	setbuf(stdout, buf);	
	while(1){
		scanf("%d",&num);
		if ( 0 == num ){
			break;
		}
		sq = (int) sqrt(num);
		if (sq * sq == num) {
			fputs("yes\n",stdout);
		}
		else{
			fputs("no\n",stdout);
		}
	}
	fflush(stdout); 
	return 0;
}