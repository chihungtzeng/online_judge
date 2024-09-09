#include <stdio.h>
#include <ctype.h>
#define MAX 20



int main()
{
    int n, i, j, sum, k;
    char str[MAX];
    while (NULL != (fgets(str, MAX, stdin)))
    {
        if (isalpha(str[0]))
        {
            sum = 0;
            for (i = 0; str[i]; i ++)
            {
                if (str[i] == 'M')
                {
                    if (str[i + 3] == 'M' && str[i + 2] == 'M' && str[i + 1] == 'M') 
                    { sum += 4000; i += 3; continue; }
                    if (str[i + 2] == 'M' && str[i + 1] == 'M') 
                    { sum += 3000; i += 2; continue; }
                    if (str[i + 1] == 'M') { sum += 2000; i += 1; continue; }
                    sum += 1000; continue;
                }
                if (str[i] == 'D')
                {
                    if (str[i + 3] == 'C' && str[i + 2] == 'C' && str[i + 1] == 'C')
                    { sum += 800; i += 3; continue; }
                    if (str[i + 2] == 'C' && str[i + 1] == 'C') 
                    { sum += 700; i += 2; continue; }
                    if (str[i + 1] == 'C') { sum += 600; i += 1; continue; }
                    sum += 500; continue;
                }
                if (str[i] == 'C')
                {
                    if (str[i + 1] == 'M') { sum += 900; i += 1; continue; }
                    if (str[i + 1] == 'D') { sum += 400; i += 1; continue; }
                    if (str[i + 2] == 'C' && str[i + 1] == 'C') 
                    { sum += 300; i += 2; continue; }
                    if (str[i + 1] == 'C') { sum += 200; i += 1; continue; }
                    sum += 100; continue;
                }
                if (str[i] == 'L')
                {
                    if (str[i + 3] == 'X' && str[i + 2] == 'X' && str[i + 1] == 'X') 
                    { sum += 80; i += 3; continue; }
                    if (str[i + 2] == 'X' && str[i + 1] == 'X') 
                    { sum += 70; i += 2; continue; }
                    if (str[i + 1] == 'X') { sum += 60; i += 1; continue; }
                    sum += 50; continue;
                }
                if (str[i] == 'X')
                {
                    if (str[i + 1] == 'C') { sum += 90; i += 1; continue; }
                    if (str[i + 1] == 'L') { sum += 40; i += 1; continue; }
                    if (str[i + 2] == 'X' && str[i + 1] == 'X') 
                    { sum += 30; i += 2; continue; }
                    if (str[i + 1] == 'X') { sum += 20; i += 1; continue; }
                    sum += 10; continue;
                }
                if (str[i] == 'V')
                {
                    if (str[i + 3] == 'I'  && str[i + 2] == 'I' && str[i + 1] == 'I') 
                    { sum += 8; i += 3; continue; }
                    if (str[i + 2] == 'I' && str[i + 1] == 'I') 
                    { sum += 7; i += 2; continue; }
                    if (str[i + 1] == 'I') { sum += 6; i += 1; continue; }
                    sum += 5; continue;
                }
                if (str[i] == 'I')
                {
                    if (str[i + 1] == 'X') { sum += 9; i += 1; continue; }
                    if (str[i + 1] == 'V') { sum += 4; i += 1; continue; }
                    if (str[i + 2] == 'I' && str[i + 1] == 'I') 
                    { sum += 3; i += 2; continue; }
                    if (str[i + 1] == 'I') { sum += 2; i += 1; continue; }
                    sum += 1; continue;
                }
            }
            printf("%d\n", sum);
        }
        else
        {
            sscanf(str, "%d", &n);
            for (;n >= 1000 && n; n -= 1000)
                printf("M");
            if (n / 100 == 9) printf("CM"), n -= 900;
            for (;n >= 500 && n; n -= 500)
                printf("D"); 
            if (n / 100 == 4) printf("CD"), n -= 400; 
            for (;n >= 100 && n; n -= 100)
                printf("C");
            if (n / 10 == 9) printf("XC"), n -= 90;
            for (;n >= 50 && n; n -= 50)
                printf("L");
            if (n / 10 == 4) printf("XL"), n -= 40; 
            for (;n >= 10 && n; n -= 10)
                printf("X");      
            if (n == 9) printf("IX"), n -= 9;       
            for (;n >= 5 && n; n -= 5)
                printf("V");
            if (n == 4) printf("IV"), n -= 4;
            for (;n >= 1 && n; n -= 1)
                printf("I");
            printf("\n");        
        }
    }
    return 0;
}