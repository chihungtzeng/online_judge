#include<stdio.h>
int main()
{
char n;
while(EOF != (n = getchar()))
{
if(n=='e'||n=='E')printf("q");
else if(n=='r'||n=='R')printf("w");
else if(n=='t'||n=='T')printf("e");
else if(n=='y'||n=='Y')printf("r");
else if(n=='u'||n=='U')printf("t");
else if(n=='i'||n=='I')printf("y");
else if(n=='o'||n=='O')printf("u");
else if(n=='p'||n=='P')printf("i");
else if(n=='['||n=='{')printf("o");
else if(n==']'||n=='}')printf("p");
else if(n=='d'||n=='D')printf("a");
else if(n=='f'||n=='F')printf("s");
else if(n=='g'||n=='G')printf("d");
else if(n=='h'||n=='H')printf("f");
else if(n=='j'||n=='J')printf("g");
else if(n=='k'||n=='K')printf("h");
else if(n=='l'||n=='L')printf("j");
else if(n==';')printf("k");
else if(n==39)printf("l");
else if(n=='c'||n=='C')printf("z");
else if(n=='v'||n=='V')printf("x");
else if(n=='b'||n=='B')printf("c");
else if(n=='n'||n=='N')printf("v");
else if(n=='m'||n=='M')printf("b");
else if(n==',')printf("n");
else if(n=='.')printf("m");
else if(n=='Z'||n=='z')printf(".");
else if(n=='x'||n=='X')printf("/");
else if(n=='a'||n=='A')printf(";");
else if(n=='S'||n=='s')printf("'");
else if(n=='q'||n=='Q')printf("{");
else if(n=='W'||n=='w')printf("}");
else if(n==' ')printf(" ");
else if(n == '\n') printf("\n");


}

return 0;
}