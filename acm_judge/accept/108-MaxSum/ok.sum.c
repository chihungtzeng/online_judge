#include <stdio.h>

#define MAX 100

int main(){
  int i, j, k;
  int n, t[MAX][MAX], sum, max;
  
  scanf("%d", &n);
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      scanf("%d", &t[i][j]);
  
  /*calculate vertical sum*/
  for(i=0; i<n; i++){
    for(j=1; j<n; j++){
      t[j][i] += t[j-1][i];
    }/*j: row*/
  }/*i: column*/
  
  max = t[0][0];
  /*find max sum*/
  for(i=0; i<n; i++){
    for(j=i; j<n; j++){
      sum = 0;
      for(k=0; k<n; k++){
        if( i==j || i==0 )
          sum += t[j][k];
        else
          sum += ( t[j][k] - t[i-1][k] );
        
        if( sum > max )
          max = sum;
        else if( sum < 0 )
          sum = 0;
      }
    }/*j: ending row*/
  }/*i: starting row*/
  
  printf("%d\n", max);
  exit(0);
}