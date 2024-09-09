import java.io.*;
import java.math.BigDecimal;

class Main {
	public static void main(String args[]){
		BigDecimal pre[], cur[],ub;
		int row;
		int i,j;
		boolean done;
		
		ub = new BigDecimal(10);
		ub = ub.pow(60);
		
		done = false;
		cur = new BigDecimal[1];
		cur[0] = new BigDecimal(1);
		System.out.println("1");
		
		row=1;
		while (!done) {
			row++;
			pre = cur;
			cur = new BigDecimal[row];
			cur[0] = new BigDecimal(1);
			cur[row-1] = new BigDecimal(1);
			for(i=1;i<row-1;i++){
				cur[i] = pre[i-1].add(pre[i]);
			}	
			System.out.print(cur[0].toPlainString());
			i = 1;
			while((i<row) && (!done)){
				System.out.print(" "+cur[i].toPlainString());
				i++;
			}
			System.out.println("");
			if(cur[(row+1)/2].compareTo(ub) >= 0){
				done = true;
			}
						
		} 
	}
}