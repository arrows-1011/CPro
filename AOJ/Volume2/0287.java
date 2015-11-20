import java.util.*;
import java.math.*;
 
public class Main {
    public static void main(String []args) {
        Scanner in = new Scanner(System.in);
        String []unit = {
            "", "Man", "Oku", "Cho", "Kei", "Gai", "Jo", "Jou", "Ko", "Kan",
                "Sei", "Sai", "Gok", "Ggs","Asg", "Nyt", "Fks", "Mts"
        };
 
        while (true) {
            BigInteger x = BigInteger.valueOf(10000);
            BigInteger M = in.nextBigInteger();
            int N = in.nextInt();
            if(N == 0){ break; }
            M = M.pow(N);
            BigInteger[] arr = new BigInteger[18];
            for(int i = 0 ; i < 18 ; i++) {
                arr[i] = M.mod(x);
                M = M.divide(x);
            }
            for(int i = 17 ; i >= 0 ; i--){
                if(arr[i].equals(BigInteger.ZERO)) continue;
                System.out.print(arr[i] + unit[i]);
            }
            System.out.println();
        }
    }
}
