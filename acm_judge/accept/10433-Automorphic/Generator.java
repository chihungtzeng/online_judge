/*
* Automorphic number generator in Java
* Tested up to 150000 numbers with Java BigInteger
*/
//package automorphic;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.logging.Level;
import java.util.logging.Logger;

//Context of search
/**
* @author Marek Mosiewicz(marek.mosiewicz[at]jotel.com.pl)
*      It is simple standard multiplication algorithm
*      The only difference is that no repeats
*      for multiplication for part already done
*      (only appending digits at the beginig to try).
*      Adds new numbers at the beginig and perfoms only
*      necessery multpilication + aggregates with already
*      done sum of previos multiplication for this column
*      Optimizations in case when 0 number found possible
*      (I currently search prefix for all combinations as long as
*      not next automorphic number is found)
*      Linearar complexity for finding n-th element from n-1 element
*      Ported from oryginal Turbo Pascal - oryginal tables were [1..MAX] - preserved
*/
public class Generator {
    //Start number can be 5 or 6 - determines which of two sequences will generate
    private static int START_NUMBER = 5;
    //Max number of digits to remember
    public static int MAX = 1000000;
    //search for TARGET iterations
    //(numbers of digits does not match
    //becouse we search for combination in case of 0)
    public static int TARGET = 3000;

    //search if given combination is automorphic number
    private static boolean isMorphic(Operational o) {
        int[] tempAggregates = new int[MAX + 20 -o.searchPostion];  //reserve
        int m;
        int n;
        int result = 0;
        //copy temporary array of aggregation in case we will not
        //find good number
        System.arraycopy(o.aggregates, 0, tempAggregates, 0, MAX - o.searchPostion+18); //18 + reserve
        int combinationStart = MAX + 1 - o.foundPosition;
        int combinationEnd = MAX + 1 - o.searchPostion;
        long tempAggregate = o.leadingAggregate;
        //for all combinations of searched prefix
        for (int x = combinationStart + 1; x <= combinationEnd; x++) {
            n = MAX;
            m = MAX - x + 1;
            long sum = 0;
            for (int y = 1; y <= x; y++) {
                result = (o.morphicNumber[n] * o.morphicNumber[m]) + tempAggregates[y];
                int modulo = result % 10;
                sum = sum + modulo;
                //new aggregate
                tempAggregates[y] = (result - modulo) / 10;
                m++;
                n--;
            }
            sum = sum + tempAggregate;
            long modulo = sum % 10;
            tempAggregate = (sum - modulo) / 10;
            sum = sum % 10;
            //if digit match
            if (sum != o.morphicNumber[MAX + 1 - x]) {
                return false;
            }
        }
        //new aggregates are correct
        o.aggregates = tempAggregates;
        o.leadingAggregate = tempAggregate;
        return true;
    }
    /**
     * Increment number. In case of switching from 9-0
     * starts combination search which is to be avoided
     * probably, but degradation of performance is not observed
     * @param o
     */
    private static void increment(Operational o) {
        boolean koniec = false;
        int i = o.foundPosition - 1;
        while (!koniec) {
            if (o.morphicNumber[i] != 9) {
                o.morphicNumber[i] = o.morphicNumber[i] + 1;
                koniec = true;
            } else {
                o.morphicNumber[i] = 0;
                if (i <= o.searchPostion) {
                    koniec = true;
                }
                i--;
            }
        }
        if (i < o.searchPostion) {
            o.searchPostion = i;
        }
    }
    /**
     * Prints number to file
     * @param output - file
     * @param o - operational context
     */
    private static void print(Writer output, Operational o) {
        try {
            for (int i = o.searchPostion; i <= MAX; i++) {
                output.append(Integer.toString(o.morphicNumber[i]));
            }
            output.append('\n');
        } catch (IOException ex) {
            Logger.getLogger(Generator.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Operational o = new Operational();
        try {
            Writer output = new BufferedWriter(new FileWriter("morphic.txt"));

            for (int i = 0; i <= MAX; i++) {
                o.aggregates[i] = 0;
                o.morphicNumber[i] = 0;
            }
            //seed
            o.morphicNumber[MAX] = START_NUMBER;
            int i = 0;
            while(i<TARGET) {
                //save only every 1000 iterations to not degrade performance
                //iteration is not equal digit in case of zeros
                if (isMorphic(o)) {
                    if (i % 1000 == 0) {
                        print(output, o);
                        System.out.println("Automorphic number nr:"+i+" found.");
                    }
                    i++;
                    o.foundPosition = o.searchPostion;
                }
                //increment value
                increment(o);
            }
            output.close();
        } catch (IOException ex) {
            Logger.getLogger(Generator.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
class Operational {
    int[] morphicNumber = new int[Generator.MAX + 1];
    int[] aggregates = new int[Generator.MAX + 1];
    long leadingAggregate = 0;
    //cuurent postion we look for
    int searchPostion = Generator.MAX;
    //current position of calculated automorphic number
    int foundPosition = Generator.MAX + 1;
}