import java.util.Scanner;

public class IsFibonacci {

    static  boolean isPerfectSquare(int x) {
        int s = (int) Math.sqrt(x);
        return (s*s == x);
    }

    static boolean isFibonacci(int n) {
        return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);
    }

    public static void main(String[] args){

        Scanner scan = new Scanner(System.in);
        int n;
        while (scan.hasNext()) {
            n = scan.nextInt();
            System.out.println(isFibonacci(n));
        }
    }
}