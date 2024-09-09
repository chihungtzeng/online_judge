import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	public static void main(String args[]){
		BigDecimal divisor,target;
		Scanner stdin;
		int nVar;
		int varpow[] = new int[100];
		int n;
		int i,j;
		
		stdin = new Scanner(System.in);
		while(stdin.hasNext()){
			n = stdin.nextInt();
			nVar = stdin.nextInt();
			for(i=0;i<nVar;i++){
				varpow[i] = stdin.nextInt();
			}
			
			target = new BigDecimal(1);
			for(i=2;i<=n;i++){
				target = target.multiply(new BigDecimal(i));
			}
			
			for(i=0;i<nVar;i++){
				for(j=2;j<=varpow[i];j++){
					target = target.divideToIntegralValue(new BigDecimal(j));
				}
			}
			System.out.println(target.toPlainString());
		}
	}
}