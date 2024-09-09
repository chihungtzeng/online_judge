#include <stdio.h>
#include <math.h>

int PerfectSquare(unsigned int n)
{
	unsigned int t, h;
   h = n & 0xF; 
    if (h > 9)
        return 0; 

    
    if ( h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8 )
    {
    
        t = (unsigned int) floor( sqrt((double) n) + 0.5 );
        return t*t == n;
    }
    return 0;
}

int main(){
	unsigned int num;
	char buf[10240];	
	setbuf(stdout, buf);	
	while(1){
		scanf("%d",&num);
		if ( 0 == num ){
			break;
		}
		
		if (PerfectSquare(num)) {
			fputs("yes\n",stdout);
		}
		else{
			fputs("no\n",stdout);
		}
	}
	fflush(stdout); 
	return 0;
}