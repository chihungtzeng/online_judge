#include<stdio.h>
#include<assert.h>
char s[10000];
int main()
{
    int i;
    while (gets(s))
        for (i=0; s[i]; i++)
            assert(s[i]>='0' && s[i]<='9' || s[i]==' ');
    return 0;
}
