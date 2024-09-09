#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 110

int solve(int len, char farm[LEN]){
    int nScarecrow = 0;
    int k = 0;
    int i;
    
    for (i=1;i<=len;i++)
        {
            if (farm[i]=='.')
            {
                k++;
                if (k==3)
                {
                    nScarecrow++;
                    k=0;
                }

            }
            else
            {
                if (k==2)
                {
                    nScarecrow++;
                    k=0;
                }
                if (k==1 && (farm[i+1]=='.' || farm[i+1]=='#'))
                {
                    nScarecrow++;
                    k=0;
                    i++;
                }
            }
        }
        if (k>0)
            nScarecrow++;
    return nScarecrow;
}

int main(){
    int nTest, k = 1, len, nScarecrow;
    char farm[LEN];
    farm[0] = '\0';
    scanf("%d", &nTest);
    while(nTest--){
        scanf("%d %s", &len, farm + 1);
        nScarecrow = solve(len, farm);
        printf("Case %d: %d\n", k++, nScarecrow);
        
    }
    return 0;
}