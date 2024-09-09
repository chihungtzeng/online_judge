import java.math.*;
import java.util.*;
import java.io.*;

public class Main {
	static BigInteger pow10[];
	static BigInteger ans[];
	static int nFound;
	final static int MAX = 501;
 
	static String  generator = "66323172405515756102352543994999345608083801190741530060056055744818709692785099775918050075416428527708162011350246806058163276171676765260937528056844214486193960499834472806721906670417240094234466197812426690787535944616698508064636137166384049029219341881909581659524477861846140912878298438431703248173428886572737663146519104988029447960814673760503957196893714671801375619055462996814764263903953007319108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625";
 
	static boolean isValidNumber(BigInteger t, int k){
		int len = t.toString().length();
		if(len != k) return false;
		else return true;		
		
		/*
		BigInteger check = t.pow(2).mod(pow10[len]);
		if(t.compareTo(check) == 0) {
			
			return true;
		}
		else {
			
			return false;
		}
		*/
	}
	
	static void generateAutoMorphicNum(int k){
		BigInteger aNum[] = new BigInteger[2];
		BigInteger tmp;
		int start, end, i;
		String first, output;
		end = generator.length();
		start = generator.length() - k;
		first = generator.substring(start, end);
		aNum[0] = new BigInteger(first);
		aNum[1] = pow10[k].add(BigInteger.ONE).subtract(aNum[0]);
		if(aNum[0].compareTo(aNum[1]) > 0){
			tmp = aNum[0];
			aNum[0] = aNum[1];
			aNum[1] = tmp;
		}
		for(i=0; i<2; i++){
			if(isValidNumber(aNum[i], k) == false){
				aNum[i] = null;
			}
		}
		for(i=0; i<2; i++){
			if(aNum[i] != null){
				System.out.print(" "+aNum[i].toString());
			}
		}
		System.out.println("");
	}	
	
	public static void main(String args[]){
		int i, kase = 1, nTest, k;
		Scanner stdin = new Scanner(System.in);
		pow10 = new BigInteger[MAX];
		
		for(i=2; i<MAX; i++){
			pow10[i] = new BigInteger("10");
			pow10[i] = pow10[i].pow(i);
		}
		nTest = stdin.nextInt();
		while(nTest > 0){
			--nTest;
			k = stdin.nextInt();
			if(k == 1){
				System.out.println("Case #"+kase+": 0 1 5 6");
				
			} else {
				System.out.print("Case #"+kase+":");
				generateAutoMorphicNum(k);
			}
			++kase;
		}
	}
}
