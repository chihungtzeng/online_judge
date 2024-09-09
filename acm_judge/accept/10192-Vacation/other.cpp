#include <iostream>
#include <cstring>
#define MAX 101


using namespace std;


char city1[MAX], city2[MAX];
int dp[MAX][MAX];


int main()
{
    int len1, len2, i, j, T = 1;
    while(1)
    {
        cin.getline(city1, MAX);
        if(city1[0] == '#' ) break;
        cin.getline(city2, MAX);
        
        len1 = strlen(city1);
        len2 = strlen(city2);
        
        for(i = 0; i < MAX; i++)
            dp[i][0] = dp[0][i] = 0;
        for(i = 1; i <= len1; i++) {
            for(j = 1; j <= len2; j++) {
                if(city1[i - 1] == city2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = (dp[i][j - 1] > dp[i - 1][j]) ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
        cout << "Case #" << T++ << ": you can visit at most "
             << dp[len1][len2] << " cities." << endl;
    }
    return 0;
}
