import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
    final static int MAX = 1700;
    public static BigInteger ans[];

    public static boolean isBigIntegerOdd(BigInteger b){
    }    
    
    public static void initAns(){
        int i;
        ans = new BigInteger[MAX];
        ans[0] = BigInteger.ZERO;
        ans[1] = BigInteger.ONE;
        for(i=2; i<MAX; i++){
            ans[i] = ans[i-1].add(ans[i-2]);
        }
        /*
        for(i=0; i<10; i++){
            System.out.println(ans[i].toString());
        }
        
        System.out.println(ans[MAX-1].toString());
        System.out.println("total length: "+ans[MAX-1].toString().length());
        */
    }
    public static void main(String args[]){
        int lineno, setno;
        Scanner stdin = new Scanner(System.in);
        
        initAns();
        while(true){
            lineno = stdin.nextInt();
            if(lineno == 0){
                break;
            }
            
            
        }
    }
}