import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String args[]){
		int n;
		BigInteger x, y, x_y;
		Scanner stdin = new Scanner(System.in);
		
		while(stdin.hasNext()){
			n = stdin.nextInt();
			x = stdin.nextBigInteger();
			y = stdin.nextBigInteger();
			
			x_y = (x.compareTo(y) > 0)? x.subtract(y) : y.subtract(x);
			System.out.println("ans["+n + "]=\"" + x_y.toString()+"\";");
			//System.out.println(n + " " + x_y.toString());
		}		
		
	}
}