import java.io.*;
import java.math.*;

class Main{
	public static void main(String args[]){
		final int MAX=901;
		int i, j;
		BigDecimal bell[][] = new BigDecimal[MAX][MAX];
		
		bell[0][0] = new BigDecimal(1);
		for(i=1; i<MAX; i++){
			bell[i][i] = new BigDecimal(bell[i-1][0].toPlainString());
			for(j=i-1; j>=0; j--){
				bell[i][j] = bell[i][j+1].add(bell[i-1][j]);
			}
		}
		//System.out.println(bell[MAX - 1][0].toPlainString());
		
		for(i=0; i<MAX; i++){
			System.out.println(bell[i][0].toPlainString());
		}
	}
}