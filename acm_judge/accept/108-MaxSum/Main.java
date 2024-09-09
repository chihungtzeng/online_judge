import java.io.*;
import java.util.*;


class Main{
	final static int DEBUG=1;
	
	public static void main(String args[]){
		Scanner stdin = new Scanner(new BufferedInputStream(System.in));
		int nRow;
		int matrix[][];
		int subm[];
		int i,j,k;
		int ans=0;
		int tmp;		
		
		nRow = stdin.nextInt();
		matrix = new int[nRow][nRow];
		subm = new int[nRow];
		for(i=0;i<nRow;i++){
			for(j=0;j<nRow;j++){
				matrix[i][j] = stdin.nextInt();
			}
		}
		for(i=1;i<nRow;i++){
			for(j=0;j<nRow;j++){
				matrix[i][j] = matrix[i-1][j] + matrix[i][j];
			}
		}
		for(i=0;i<nRow;i++){
			for(j=i;j<nRow;j++){
				if(i == j) {
					for(k=0;k<nRow;k++){
						subm[k] = matrix[i][k];
					}
				}
				else {
					for(k=0;k<nRow;k++){
						subm[k] = matrix[j][k] - matrix[i][k];
					}
				}
				tmp = findMax(subm);
				if (tmp > ans){
					ans = tmp;
				}
			}
		}
		System.out.println(""+ans);
	}
	static int findMax(int a[]){
		int i;
		int sum=0;
		int max=0;
		for(i=0;i<a.length;i++){
			sum = sum + a[i];
			if (sum > max){
				max = sum;
			}
			if (sum < 0){
				sum = 0;
			}
		}
		return max;
	}
}