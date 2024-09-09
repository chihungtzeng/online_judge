import java.io.*;
import java.math.*;
import java.util.*;

class Main{
	public static void main(String args[]){
		BigDecimal a, b, c, limit;
		
		String operator;
		Scanner stdin = new Scanner(System.in);
		
		limit = new BigDecimal("2147483648");
		/*System.out.println("limit="+limit.toPlainString());*/
		c = new BigDecimal(0);
		while(stdin.hasNext()){
			a = stdin.nextBigDecimal();
			operator = stdin.next();
			b = stdin.nextBigDecimal();
			if (operator.compareTo("+") == 0){
				c = a.add(b);
			}
			else if (operator.compareTo("*") == 0){
				c = a.multiply(b);
			}
			/*System.out.println(a.toPlainString() + " " + b.toPlainString() + " " + c.toPlainString());*/
			System.out.println(a.toPlainString() + " " + operator + " " + b.toPlainString());
			if(a.compareTo(limit) >= 0){
				System.out.println("first number too big");
			}
			if(b.compareTo(limit) >= 0){
				System.out.println("second number too big");
			}
			if(c.compareTo(limit) >= 0){
				System.out.println("result too big");
			}
		}
	}
}