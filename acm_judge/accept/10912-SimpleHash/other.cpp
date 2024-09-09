#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int i,x,j,m,l,s,cnt=0,res,num[352][27][27];
    for(i=0;i<352;i++){
        for(j=0;j<27;j++){
            for(m=0;m<27;m++){
                num[i][j][m] = 0;
            }
        }
    }
    for(m=1;m<27;m++){
        for(i=1;i<=m;i++){
              num[i][1][m]=1;
        }
    }
    for(j=2;j<27;j++){
        for(i=j+1;i<352;i++){
            for(m=2;m<27;m++){
                for(x=1; x<=27-j && i-j*x>=j-1 && x<m; x++){
                    num[i][j][m]+=num[i-j*x][j-1][m-x];
                }
            }
        }
    }
    while(cin>>l>>s && (l!=0&&s!=0)){
        if(l>26||s>351) res=0;
        else res=num[s][l][26];
        cout<<"Case "<<++cnt<<": "<<res<<endl;
    }
    return 0;
}
