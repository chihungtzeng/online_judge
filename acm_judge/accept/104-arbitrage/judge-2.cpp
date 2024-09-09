#include <iostream>          
#include <vector>
#include <algorithm>

#define N 20

using namespace std;

int main()
{
    int n, last_p[N][N][N], num, ptr, ptr2;
    double value[N][N][N], temp;
    vector<int> seq;
    
    while(cin >> n)
    {
       
        for(int m = 0; m < n; m++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    value[m][i][j] = 0.0, last_p[m][i][j] = -1;
        
        ptr = -1;
        

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    value[0][i][j] = 1.0;
                else
                    cin >> value[0][i][j];
            }
        }
        
 
        for(int m = 1; m < n; m++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    for(int k = 0; k < n; k++)
                    {
                        temp = value[m-1][i][k] * value[0][k][j];
                        
                        if(value[m][i][j] < temp)
                        {
                            value[m][i][j] = temp;
                            last_p[m][i][j] = k;
                        }
                    }
                }
                
                
                if(value[m][i][i] > 1.01)
                {
                    num = m, ptr = i;
                    goto print_result;
                }
            }
        }
        
        print_result:
        {
            
            if(ptr < 0)
            {
                cout << "no arbitrage sequence exists\n";
                continue;
            }
            
            
            seq.clear();
            seq.push_back(ptr);
            ptr2 = last_p[num--][ptr][ptr];
            
            while(num >= 0)
            {
                seq.push_back(ptr2);
                ptr2 = last_p[num--][ptr][ptr2];
            }
            
            cout << ptr+1;
            
            for(int i = seq.size()-1; i >= 0; i--)
                cout << ' ' << seq[i]+1;
            
            cout << endl;
        }
    }
    
    return 0;
}
