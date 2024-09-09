#include <stdio.h>
#define F(x) freopen(x ".in","w",stdout)
void p(const char *s,int count)
{
while(--count >= 0) printf("%s",s);
}
int main(void)
{
int i,k;
unsigned int x;
char z[256];
F("1");p("122",42);fclose(stdout);
F("2");p("122",43);fclose(stdout);
F("3");p("1333",32);fclose(stdout);
F("4");p("aabb",32);fclose(stdout);
F("5");p("aabbc",26);fclose(stdout);
F("6");p("aacbb",26);fclose(stdout);
F("7");p("ab",64);p("22",1);p("ab",64);fclose(stdout);
F("8");for(i=1;i<=128;i++) {z[0]='a'+(i&1);z[1]=0;p(z,i);} fclose(stdout);
F("9");
x = 239;
for(k=1;k<=10000;k++) for(i='a';i<='z';i++)
  {
    z[0]=i;
      z[1]=0;
        x = 1664525 * x + 1013904223;
	  p(z,(x % 3) + 1);
	    }
	    fclose(stdout);
	    return 0;
	    }
