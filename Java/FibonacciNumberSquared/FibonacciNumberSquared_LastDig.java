package Java.FibonacciNumberSquared;

import java.util.Scanner;

public class FibonacciNumberSquared_LastDig {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number: ");
        
        int n = in.nextInt();

        int result = fibSquared_LastDig(n);
        System.out.println("Result = " + result);

        in.close();
    }

    public static int fibSquared_LastDig(int n){
        if(n <= 0){
            return 0;
        }

        //Create dp array
        int fib[] = new int[n+1];
        fib[0] = 0;
        fib[1] = 1;

        //Initialize sum 
        int sum = 1;

        //Update dp array with proper fib value and add new value squared to sum
        for(int i = 2; i <= n; i++){
            fib[i] = (fib[i-1]+fib[i-2]);
            sum += fib[i] * fib[i];
        }

        //Get last number of sum
        int result = sum%10;

        return result;
    }
}