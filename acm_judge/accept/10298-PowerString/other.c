#include <stdio.h>
#include<string.h>
#define MAX 10000001
char s[MAX];

main(){
   int i,j,k,m,n,l;
   while (gets(s) && strcmp(s,".")) {
      l = m = n = strlen(s);
      for (i=2;i<=n;i++) {
         while (n%i == 0) {
            n /= i;
            for (j=0;j<m-m/i && s[j] == s[j+m/i];j++);
            if (j == m-m/i) m /= i;
         }
      }
      printf("%d\n", l/m);
   }
}
