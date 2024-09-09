#include <stdio.h>
#include <string>
#include <map>
using namespace std;

char word[27] = "abcdefghijklmnopqrstuvwxyz";
bool mk[27]; 
map<string, int> hash;
int num;

void build(int pos, int deep)
{
    if(!deep)
    {
        num++;
        char tmp[6];
        int len = 0;
        for(int i = 0; i < 26; i++)
        {
            if(mk[i]) tmp[len++] = word[i];
        }
        tmp[len] = 0;
        hash[(string)tmp] = num;
        return;
    }
    if(pos >= 26) return;
    mk[pos] = 1;
    build(pos + 1, deep - 1);
    mk[pos] = 0;
    build(pos + 1, deep);
}

int main()
{
    num = 0;
    for(int i = 1; i < 6; i++) build(0, i);
    char data[6];
    
    while( 1 == scanf("%s", data)){
    	printf("%d\n", hash[data]);
    }
    return 0;
} 