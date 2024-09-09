#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define q_num "474.txt"
#define verbose 0

const int DEBUG = 0;


int main()
{

  FILE *fp;
  int temp;		

  if(DEBUG)
  {		
    fp = fopen(q_num,"r");		
    if (NULL == fp) 
    {			
      printf("open file failed\n");
      /*exit(1);*/		
    }	
  }	
  else
  {		
    fp = stdin;	  
  }		
    
  int n;
  
  while(fscanf(fp,"%d",&n) != EOF)
  {
    int i;
    
    if(verbose)
    printf("n %d\n",n);
    
    double in = 1;
    
    int count = 0;
    for(i=0;i<n;i++)
    {
      in = in/2.0;
      while(in < 1)
      {
        in = in*10;
        count++;
      }
    }
    
    printf("2^-%d = %.3lfe-%d\n",n,in,count);
    
    
    
  }
  






    exit(0);


}/* end main*/
