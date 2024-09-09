import java.io.*;
import java.util.*;
import java.math.*;

class Main{
	public static void main(String args[]){
		int nTest;
		StringBuffer sb1, sb2, result;;
		BigDecimal bd1,bd2;
		Scanner stdin = new Scanner(System.in);		
		int i;
		
		nTest = stdin.nextInt();
		for(i=0;i<nTest;i++){
			sb1 = new StringBuffer(stdin.next());
			sb2 = new StringBuffer(stdin.next());
			sb1 = sb1.reverse();
			sb2 = sb2.reverse();
			bd1 = new BigDecimal(sb1.toString());
			bd2 = new BigDecimal(sb2.toString());
			bd1 = bd1.add(bd2);
			result = new StringBuffer(bd1.toPlainString());
			result = result.reverse();
			bd1 = new BigDecimal(result.toString());
			System.out.println(bd1.toPlainString());
		}
	}
	
}