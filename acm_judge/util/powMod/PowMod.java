import java.math.*;

public class PowMod{
	public static void main(String args[]){
		if(args.length < 3){
			System.out.println("usage: prog base exp mod");
			System.exit(0);
		}
		
		BigInteger b, e, m, result;
		b = new BigInteger(args[0]);
		e = new BigInteger(args[1]);
		m = new BigInteger(args[2]);
		result = b.modPow(e, m);
		
		System.out.println(args[0]+"^"+args[1]+" % " + args[2] + " = " + result.toString());
		
	}
}
