/*
*Problem:Uva 11456 -- trainsorting
*Algorithm:DP
*Date:2011.3.21
*/
#include<cstdio>
#include<cstdlib>
#include<string.h>
#define N 2001
int n,a[N],dp[2][N],ans;
void deal(int a[N],int dp[N],bool flag){
    for (int i=0;i<n;i++){
        int best=0;
        for (int j=0;j<i;j++)
            if (a[j]>a[i]==flag && dp[j]>best) best=dp[j];
        dp[i]=best+1;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            a[n-i-1]=x;
        }
        deal(a,dp[0],0);
        deal(a,dp[1],1);
        ans=0;
        for (int i=0;i<n;i++){
            int temp=dp[0][i]+dp[1][i]-1;
            ans=ans>temp?ans:temp;
        }
        printf("%d\n",ans);
    }
}
