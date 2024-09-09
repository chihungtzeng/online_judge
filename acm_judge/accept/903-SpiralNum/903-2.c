/*AC*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int square(long int x){
	return x*x;
}

long int numAt(long int foldk, long int mth){
	long int start;
	mth = (mth + (foldk << 3)) % ((foldk << 3));
	start = square(2 * foldk - 1) + 1;
	return start + mth;

}


int main(){
	long int foldk, mth;
	long int input;	
	long int inner, outter;
	long int base[5][5] = {
		{21, 22, 23, 24, 25},
		{20, 7, 8, 9, 10},
		{19, 6, 1, 2, 11},
		{18, 5, 4, 3, 12},
		{17,16, 15, 14, 13}
	};
	
	while(1 == scanf("%ld",&input)){	
		if(input <= 9){
			int x, y, i, j;
			for(i=0; i<5;i++){
				for(j=0;j<5;j++){
					if(base[i][j] == input){
						x = i;
						y = j;
					}
				}
			}
			printf("%ld;%ld;%ld;\n",base[x-1][y-1],base[x-1][y],base[x-1][y+1]);
			printf("%ld;%ld;%ld;\n",base[x][y-1],base[x][y],base[x][y+1]);
			printf("%ld;%ld;%ld;\n",base[x+1][y-1],base[x+1][y],base[x+1][y+1]);
			continue;
		}
		
		foldk = sqrt(input - 1);
		foldk = (foldk % 2 == 0)? foldk >> 1 : (foldk >> 1) + 1;
		mth = input - 1 - square(2 * foldk - 1);
		
		if(mth == 0){			
			printf("%ld;%ld;%ld;\n", square((foldk << 1) +1) - 1, square((foldk << 1)+1), square((foldk << 1)+1)+1);
			printf("%ld;%ld;%ld;\n", input - 1, input, numAt(foldk+1, 1));
			printf("%ld;%ld;%ld;\n", numAt(foldk - 1,0), input + 1, numAt(foldk+1, 2));
		}
		else if ((mth > 0) && (mth < (foldk << 1) -2)){
			inner = numAt(foldk - 1, mth - 1);
			outter = numAt(foldk + 1, mth + 1);
			printf("%ld;%ld;%ld;\n", numAt(foldk-1, mth -2), input - 1, outter -1);
			printf("%ld;%ld;%ld;\n", inner, input, outter);
			printf("%ld;%ld;%ld;\n", inner+1, input + 1, outter+1);
		}
		else if(mth == (foldk << 1) - 2){
			inner = numAt(foldk -1, (foldk << 1) -3);
			outter = numAt(foldk + 1, mth + 1);
			printf("%ld;%ld;%ld;\n", inner -1, input - 1, outter  -1 );
			printf("%ld;%ld;%ld;\n", inner , input, outter );
			printf("%ld;%ld;%ld;\n", input + 2, input + 1, outter + 1);
		}
		else if(mth == (foldk << 1) - 1){
			inner = numAt(foldk -1, (foldk << 1) -3);
			outter = numAt(foldk + 1,(foldk << 1) + 1);
			printf("%ld;%ld;%ld;\n", inner, input - 1, outter  -2 );
			printf("%ld;%ld;%ld;\n", input + 1, input, outter - 1);
			printf("%ld;%ld;%ld;\n", outter + 2, outter + 1, outter);
		}
		else if(mth == (foldk << 1) ){
			inner = numAt(foldk -1, mth -3);
			outter = numAt(foldk + 1, mth + 3);
			printf("%ld;%ld;%ld;\n", inner + 1, inner, input  -2 );
			printf("%ld;%ld;%ld;\n", input + 1, input, input - 1);
			printf("%ld;%ld;%ld;\n", outter + 1, outter , outter -1);
		}
		else if ((mth > (foldk << 1)) && (mth < (foldk << 2) -2)){
			inner = numAt(foldk - 1, mth - 3);
			outter = numAt(foldk + 1, mth + 3);
			printf("%ld;%ld;%ld;\n", inner + 1, inner, inner -1);
			printf("%ld;%ld;%ld;\n", input+1, input, input-1);
			printf("%ld;%ld;%ld;\n", outter+1, outter , outter-1);
		}
		else if(mth == (foldk << 2) - 2){
			inner = numAt(foldk -1,  mth - 3);
			outter = numAt(foldk + 1, mth + 3);
			printf("%ld;%ld;%ld;\n", input + 2, inner, inner -1 );
			printf("%ld;%ld;%ld;\n", input + 1, input, input - 1);
			printf("%ld;%ld;%ld;\n", outter + 1, outter , outter -1);
		}
		else if(mth == (foldk << 2) - 1){
			inner = numAt(foldk -1,  (foldk << 2) - 5);
			outter = numAt(foldk + 1, (foldk << 2) + 3);
			printf("%ld;%ld;%ld;\n", outter + 2, input + 1, inner );
			printf("%ld;%ld;%ld;\n", outter + 1, input, input - 1);
			printf("%ld;%ld;%ld;\n", outter, outter - 1, outter -2);
		}
		else if(mth == (foldk << 2)){
			inner = numAt(foldk -1,  mth - 5);
			outter = numAt(foldk + 1, mth + 5);
			printf("%ld;%ld;%ld;\n", outter + 1, input+1, inner + 1 );
			printf("%ld;%ld;%ld;\n", outter , input, inner);
			printf("%ld;%ld;%ld;\n", outter - 1, input - 1 , input -2);
		}
		else if((mth > (foldk << 2)) && (mth < (foldk << 2) + (foldk << 1) -2)){
			inner = numAt(foldk -1,  mth - 5);
			outter = numAt(foldk + 1, mth + 5);
			printf("%ld;%ld;%ld;\n", outter + 1, input+1, inner + 1 );
			printf("%ld;%ld;%ld;\n", outter , input, inner);
			printf("%ld;%ld;%ld;\n", outter - 1, input - 1 , inner -1);
		}
		else if(mth == (foldk << 2) + (foldk << 1) - 2){
			inner = numAt(foldk -1,  mth - 5);
			outter = numAt(foldk + 1, mth + 5);
			printf("%ld;%ld;%ld;\n", outter + 1, input+1, input + 2 );
			printf("%ld;%ld;%ld;\n", outter , input, inner);
			printf("%ld;%ld;%ld;\n", outter - 1, input - 1 , inner - 1);
		}
		else if(mth == (foldk << 2) + (foldk << 1) - 1){
			inner = numAt(foldk -1,  (foldk << 2) + (foldk << 1) - 7);
			outter = numAt(foldk + 1, (foldk << 2) + (foldk << 1) + 5);
			printf("%ld;%ld;%ld;\n", outter, outter + 1, outter + 2 );
			printf("%ld;%ld;%ld;\n", outter - 1, input, input + 1);
			printf("%ld;%ld;%ld;\n", outter - 2, input - 1, inner);
		}
		else if(mth == (foldk << 2) + (foldk << 1)){
			inner = numAt(foldk -1,  mth -7);
			outter = numAt(foldk + 1, mth + 7);
			printf("%ld;%ld;%ld;\n", outter-1 , outter , outter + 1 );
			printf("%ld;%ld;%ld;\n", input - 1, input, input + 1);
			printf("%ld;%ld;%ld;\n", input - 2, inner, inner + 1);
		}
		else if((mth > (foldk << 2) + (foldk << 1))&&(mth < (foldk << 3)-1)){
			inner = numAt(foldk -1,  mth -7);
			outter = numAt(foldk + 1, mth + 7);
			printf("%ld;%ld;%ld;\n", outter-1 , outter , outter + 1 );
			printf("%ld;%ld;%ld;\n", input - 1, input, input + 1);
			printf("%ld;%ld;%ld;\n", inner - 1, inner, inner + 1);
		}
		else if(mth == (foldk << 3) - 1){
			inner = numAt(foldk -1,  (foldk << 3) - 9);
			outter = numAt(foldk + 1, (foldk << 3) + 7);
			printf("%ld;%ld;%ld;\n", outter -2 , outter -1 , outter);
			printf("%ld;%ld;%ld;\n", input - 1, input, input + 1);
			printf("%ld;%ld;%ld;\n", inner, inner + 1, input + 2);
		}
		else{
			printf("unprocessed input:%ld foldk:%ld mth:%ld\n",input,foldk,mth);
		}
	}
	return 0;
}
