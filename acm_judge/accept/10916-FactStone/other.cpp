#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

const double eps = 1e-10;

main(){
  int in;
  double log4=log(4),log2=log(2);
  while(cin>>in && in){
    int loop = (in-1960)/10;
    double bit = 4;
    rep(i,loop){
      bit*=2;
    }
    double input = (bit)*log2;
    double tmp = 0;
    
    for(int i=1;;i++){
      tmp+=log((double)i);
      if (!(tmp < input)){
	cout << i-1 << endl;
	break;
      } 
    }

  }
  
}
