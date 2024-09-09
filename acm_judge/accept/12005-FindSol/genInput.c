#include <stdio.h>
#include <stdlib.h>
#define MAX 100000000000000LL
#define NUM 30000

int main(){
   long long i;
	long long t;
	int count = 10000;
	
   srand(time(NULL));
   for(i=1; i<NUM; i++){
   	printf("%lld\n",i);
   }
   for(i=0; i<NUM; i++){
   	t = llabs( (rand()*rand()) % MAX);
   	if(t != 0){ 
   		printf("%lld\n", t);
   	}
	}
	for(t=MAX, count=1000; count >= 0; --count){
		printf("%lld\n", t - count);
	}
	i = 10000000 - 1;
	printf("%lld\n", i*i);
	printf("0\n");
	return 0;
}
