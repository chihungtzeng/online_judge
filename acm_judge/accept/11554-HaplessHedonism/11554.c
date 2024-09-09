#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000001

unsigned long long sum(int s,int t)
{
    unsigned long long result;
    
    result = ((abs(t-s) + 1LL) * (t + s)) >> 1;
    
    return result;
}

void calcAns(unsigned long long *ans){
    int i, n;
    memset(ans, 0, sizeof(unsigned long long)*MAX);
    ans[4] = 1;
    for(i=5;i<MAX;i++)
	{
		n = (i >> 1) + 1;
		ans[i] = ans[i-1] + sum(1,n-2) + sum(i-n-1,1);
	}
}

int main()
{
	int nTest,nStick;
    unsigned long long *ans;
    
    ans = (unsigned long long *) malloc(sizeof(unsigned long long)*MAX);
    calcAns(ans);	

#if 0
    int i;
    for(i=MAX-1000; i<MAX; i++){
        printf("%llu\n", ans[i]);
    }        
#endif    
    
	scanf("%d",&nTest);
	while(1 == scanf("%d", &nStick))
	{
		printf("%llu\n",ans[nStick]);
	}
	
	free(ans);
	return 0;
}