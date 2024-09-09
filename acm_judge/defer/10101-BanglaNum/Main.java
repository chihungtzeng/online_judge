import java.io.*;
import java.util.*;
import java.math.BigDecimal;


class Main{
	public static void main(String args[]){
		Scanner stdin = new Scanner(System.in);
		BigDecimal bi,kuti,lakh,hajar,shata;
		BigDecimal result[] = new BigDecimal[2];
		StringBuffer sb;
		int sn=1;
		
		
		while(stdin.hasNext()){
			bi = stdin.nextBigDecimal();
			result = bi.divideAndRemainder(new BigDecimal("10000000"));
			kuti = result[0];
			bi = result[1];
			result = bi.divideAndRemainder(new BigDecimal(100000));
			lakh = result[0];
			bi = result[1];
			result = bi.divideAndRemainder(new BigDecimal(1000));
			hajar = result[0];
			bi = result[1];
			result = bi.divideAndRemainder(new BigDecimal(100));
			shata = result[0];
			bi = result[1];
			sb = new StringBuffer();
			sb.append(sn+".");
			if (kuti.compareTo(new BigDecimal(0)) == 0){
				sb.append(" "+kuti.toPlainString()+" kuti");
			}
			if (lakh.compareTo(new BigDecimal(0)) == 0){
				sb.append(" "+lakh.toPlainString()+" lakh");
			}
			if (hajar.compareTo(new BigDecimal(0)) == 0){
				sb.append(" "+kuti.toPlainString()+" hajar");
			}
			if (shata.compareTo(new BigDecimal(0)) == 0){
				sb.append(" "+shata.toPlainString()+" shata");
			}
			if (bi.compareTo(new BigDecimal(0)) == 0){
				sb.append(" "+bi.toPlainString());
			}
			System.out.println(sb.toString());
			sn++;
		}
	}
}