import java.util.Scanner;

public class AutomorphicNumber {
    public static void main(String args[]){
        
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number: ");

        int number = in.nextInt();

        int count = 0;
        int copyNum = number;  //just a copy of number to perform counting operation

        //count the digits of the number given by user
        while(copyNum > 0)
        {
            copyNum = copyNum / 10;
            count++;
        }
        //taking last digit of squared number
        int squareOfNumber = (int) Math.pow(number, 2);
        int lastDigit = (int) (squareOfNumber % (Math.pow(10, count)));
        //checking if the situation for automorphic number is fulfilled
        if(number == lastDigit)
        {
            System.out.println(number + " is an Automorphic number.");
            System.out.println("As, square of " + number + " = "+ 
                                squareOfNumber + " and it ends with number " + lastDigit + ".");
        }
        else
        {
            System.out.println(number + " is not an Automorphic number.");
            System.out.println("As, square of " + number + " = " +
                                squareOfNumber + " and it ends with number " + lastDigit + ".");
        }
    }
}