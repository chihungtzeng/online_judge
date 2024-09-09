import java.io.*;
import java.util.*;


class Main{
	public static  int digitProduct(int n){
		int result=1;
		while(n>0){
			result = result * (n % 10);
			n = n/10;
		}
		return result;
	}
	public static void main(String args[]){
		final boolean debug = false;
		Scanner stdin = new Scanner(new BufferedInputStream(System.in));
		Hashtable<Integer, Integer> ht = new Hashtable();
		int max,nInput,input[];		
		int i,j,v;
		
		max=0;
		nInput = stdin.nextInt();
		input = new int[nInput];
		for(i=0;i<nInput;i++){
			input[i] = stdin.nextInt();
			max = (input[i]>max)? input[i] : max;
			max = (max>387420489)? 387420489: max;
		}
	
		for(i=1;i<=max;i++){
			v = digitProduct(i);
			if(!ht.containsKey(v)){
				ht.put(v,i);
			}
		}
		
		for(i=0;i<nInput;i++){
			v = input[i];
			if(ht.containsKey(v)){
				System.out.println(""+ht.get(v));
			}
			else {
				System.out.println("-1");
			}
		}
		
		if(debug){
			int x;
			Enumeration myenum = ht.keys();
			while(myenum.hasMoreElements()){
				x = (Integer) myenum.nextElement();
				System.out.println(""+x+" : "+ht.get(x));
			}
		}
	}
}

