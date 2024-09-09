#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 70
#define TRUE 1
#define FALSE 0


short n,sum,aim,num,a[MAXN];
char used[MAXN];

int cmp(const void *a,const void *b)
{
    return (*(short *)b)-(*(short *)a);
}

int dfs(short Stick,short len,short pos)
{
	short i;
    char sign = (len==0)? TRUE : FALSE;
  
    if(Stick==num)
      return TRUE;
    for(i=pos+1;i<n;i++)
    {
       if(used[i]) continue;
       if(len+a[i]==aim)
       {
          used[i]=TRUE;
          if(dfs(Stick+1,0,-1))
            return TRUE;
          used[i]=FALSE;
          return FALSE;
       }
       else if(len+a[i]<aim)
       {
          used[i]=TRUE;
          if(dfs(Stick,len+a[i],i))
            return TRUE;
          used[i]=FALSE;
          if(sign) return FALSE;
          while(a[i]==a[i+1]) i++;
       }
    }
    return FALSE;
}
int main(){
	short i;
    while(scanf("%hd",&n)==1)
    {
       if(n==0) break;
       memset(a,0,sizeof(a));
       sum=0;
       for(i=0;i<n;i++)
       {
          scanf("%hd",&a[i]);
          sum+=a[i];
          
       }

       qsort(a,n,sizeof(a[0]),cmp);

       for(aim = a[n-1];aim<=sum;aim++)
         if(sum%aim==0)
         {
            num=sum/aim;
            memset(used, FALSE, sizeof(used));
            if(dfs(1,0,-1))
            {
               printf("%hd\n",aim);
               break;
            }
         }
    }
	return 0;
}
