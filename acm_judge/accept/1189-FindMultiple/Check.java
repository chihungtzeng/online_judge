import java.io.*;
import java.util.*;
import java.math.*;

public class Check {
	public static void main(String args[]){
		BigInteger n, multiple, result;
		Scanner stdin = new Scanner(System.in);
		while(stdin.hasNext()){
			n = stdin.nextBigInteger();
			multiple = stdin.nextBigInteger();
			result = multiple.mod(n);
			if(result.compareTo(BigInteger.ZERO) == 0){
				System.out.println(n.toString() + ": OK");
			} else {
				System.out.println(n.toString() + ": Wrong Answer");
			}
		}
	}
}