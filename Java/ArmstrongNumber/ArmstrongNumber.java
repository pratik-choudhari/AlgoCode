package Java.ArmstrongNumber;

import java.util.*;

public class ArmstrongNumber
 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a positive no.:");
        int n = sc.nextInt();


        for (int i = 1; i < n; i++) {
            int noOfDigits = (int) Math.floor(Math.log10(i) + 1);
            int org = i;
            int sum = 0;
            while (org > 0) {
                int digit = org % 10;
                sum += (int) Math.pow(digit, noOfDigits);
                org /= 10;
            }
            if (sum == i) {
                System.out.print(i + " ");
            }
        }
        sc.close();

    }
}
