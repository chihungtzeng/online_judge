import java.math.*;

public class Main {
    public static void main(String args[]){
        BigDecimal ans, up, down;
        MathContext mc;
        up = new BigDecimal("1");
        down = new BigDecimal("103");
        mc = new MathContext(30, RoundingMode.HALF_UP);
        ans = up.divide(down, mc);
        System.out.println(ans.toPlainString());
    }
}