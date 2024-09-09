#include<stdio.h>
#include<stdlib.h>
int main() {
    char a,b,x,y,m,n,*p="@BBT;9KK2DBT;;KKBBDTKKKMDDTTMMM]";
    while (scanf("%c%c %c%c\n",&a,&b,&x,&y)>3) {
        m=abs(a-x);
        n=abs(b-y);
        printf("To get from %c%c to %c%c takes %d knight moves.\n",a,b,x,y,
        	(6&(a|b))&&(6&(x|y))||m*n-1?p[n*4+m/2]-40>>m%2*3&7:4);
    }
    return 0;
}
