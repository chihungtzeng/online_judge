import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		BigInteger a, b, result;
		String op;
		
		while(stdin.hasNext()){
			a = stdin.nextBigInteger();
			op = stdin.next();
			b = stdin.nextBigInteger();
			if(op.compareTo("/") == 0){
				result = a.divide(b);
			} else {
				result = a.mod(b);
			}
			System.out.println(result.toString());
		}
	}
}