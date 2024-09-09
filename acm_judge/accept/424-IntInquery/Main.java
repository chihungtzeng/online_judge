import java.util.*;
import java.io.*;
import java.math.BigDecimal;

class Main{
	public static void main(String args[]){
		BigDecimal ba, bb;
		Scanner stdin = new Scanner(System.in);
		ba = new BigDecimal(0);
		while(stdin.hasNext()){
			bb = stdin.nextBigDecimal();
			ba = ba.add(bb);
		}
		System.out.println(ba.toPlainString());
	}
}