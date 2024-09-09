#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 

int sarr[1200][1200];

char input[1200];

 

 

int Palindrome(int , int );

 

 

main()

{

    int num;

    int length;

    int i, j,k;

    int output;

    

    gets(input);

    num=atoi(input);

 

    for(k=0;k<num;k++) {

        gets(input);

        length = strlen(input);

        

        for(i=0;i<1000;i++) {

            for(j=0;j<1000;j++) {

                sarr[i][j]=-1;

            }

        }

        if(length == 0) {

            output=0;

        }

        else {

            output = Palindrome(0, length-1);

        }

        printf("%d\n", output);

    }
	return 0;
}

 

 

int Palindrome(int low, int high)

{

    if(sarr[low][high] > 0) {

        return sarr[low][high];

    }

 

    if(low==high) {

        return 1;

    }

    if(input[low]==input[high] && low+1 == high){

        return 2;

    }

    

    if(input[low]==input[high]){

        sarr[low][high] = 2 + Palindrome(low+1, high-1);

        return sarr[low][high];

    }

 

        

    sarr[low+1][high]=Palindrome(low+1, high);

    sarr[low][high-1]=Palindrome(low, high-1);

    

    if(sarr[low+1][high] > sarr[low][high-1]) {

        return sarr[low+1][high];

    }

    else {

        return sarr[low][high-1];

    }

}

 