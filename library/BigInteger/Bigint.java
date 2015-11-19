import java.math.BigInteger;
import java.util.Scanner;

public class Bigint{
    public static void main(String [] args){
        //初期化
        BigInteger A = BigInteger.valueOf(114);
        System.out.println(A);

        //BigIntegerのゼロを表す。他にも.ONEや.TENがある。
        BigInteger B = BigInteger.ZERO;

        B = BigInteger.valueOf(400);
        //加算 B.add(A)ではBの値は変更されない。 変更するにはB = B.add(A)とする。
        System.out.println(B.add(A));
        //減算
        System.out.println(B.subtract(A));
        //乗算
        System.out.println(B.multiply(A));
        //除算
        System.out.println(B.divide(A));
        //剰余算
        System.out.println(B.remainder(A));
        
        BigInteger C = BigInteger.ONE;
        BigInteger D = BigInteger.TEN;
        
        //比較 ＝
        if(C.equals(D)){
            System.out.println("Equals");
        }else{
            System.out.println("Not equals");
        }
        //比較 <
        if(C.compareTo(D) == -1){
            System.out.println("C < D");
        }
        C = BigInteger.TEN;
        D = BigInteger.ONE;
        //比較 >
        if(C.compareTo(D) == 1){
            System.out.println("C > D");
        }
        C = BigInteger.ONE;
        //比較 =
        if(C.compareTo(D) == 0){
            System.out.println("C == D");
        }
        C = BigInteger.ZERO;
        //max
        BigInteger E = C.max(D);
        System.out.println(E);
        //min
        BigInteger F = C.min(D);
        System.out.println(F);
        //intに変換 ただしintの範囲に注意が必要。
        int G = D.intValue();
        //longに変換 ただしlongの範囲に注意が必要。
        long H = D.longValue();
        //素数である可能性が高いものはtrue, 引数は呼び出し側が許容しない確率の尺度。素数である確率は(1-1/(2^引数))を超える。
        C = C.add(BigInteger.ONE);
        if(C.isProbablePrime(20)){
            System.out.println("Prime");
        }
    }
}
