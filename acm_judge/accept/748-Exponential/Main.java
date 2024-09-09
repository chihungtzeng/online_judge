import java.io.*;
import java.util.*;
import java.math.*;
/*Cannot produce correct string*/

class Main{
	public static StringBuilder trimStringBuilderTail(StringBuilder sb){
			int pointPos,i;
			boolean done;
			
			pointPos = sb.indexOf(".");
			if (pointPos == -1) return sb;			
			done = false;
			i = sb.length() - 1;
			while(!done) {
					if (sb.charAt(i) != '0'){
						done = true;
					}
					else{
						i--;
					}
			}
			if (sb.charAt(i) == '.') { i--; }
			
			sb = new StringBuilder(sb.substring(0,i+1));
			return sb;
		}
	public static StringBuilder trimStringBuilderHead(StringBuilder sb){
		int i;
		boolean done;

		done = false;
		i=0;
		while(!done){
			if((i < sb.length()) &&(sb.charAt(i) == '0')){ i++; }
			else { done = true; }
		}
		return new StringBuilder(sb.substring(i,sb.length()));
	}
	public static void main(String args[]){
		
		int e,pointPos,nDigit;
		BigDecimal bi;
		Scanner stdin = new Scanner(System.in);
		StringBuilder base,ans, test, sbtmp;
		
		boolean isFloat;
		/*
		test = new StringBuilder("0023.00000");
		test = trimStringBuilder(test);
		pointPos = test.indexOf(".");
		nDigit = test.length() - pointPos - 1;
		System.out.println(test.toString() +" with " + nDigit + " digits behind");
		*/
		
		while(stdin.hasNext()){
			base = new StringBuilder(stdin.next());
			base = trimStringBuilderTail(base);
			pointPos = base.indexOf(".");
			nDigit = base.length() - pointPos - 1;
			e = stdin.nextInt();			
			isFloat = (pointPos == -1)? false : true;
			
			if (isFloat){
				nDigit = nDigit * e;
				base = new StringBuilder(base.substring(0,pointPos) + base.substring(pointPos+1,base.length()));
				 
				bi = new BigDecimal(base.toString());
				bi = bi.pow(e);
				ans = new StringBuilder(bi.toPlainString());
				while(ans.length() < nDigit){
					ans = ans.insert(0,'0');
				}
				ans = ans.insert(ans.length()-nDigit, '.');
			}
			else{
				bi = new BigDecimal(base.toString());
				bi = bi.pow(e);
				ans = new StringBuilder(bi.toPlainString());
			}
			ans = trimStringBuilderHead(ans);
			System.out.println(ans.toString());
			
		}
		
	}
}