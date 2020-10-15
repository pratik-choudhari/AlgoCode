import java.util.Scanner;

public class PalindromicPyramid {

    public static void main(String[] args) {
        int total_rows, row, valup, valdown;

        // taking user input
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of rows: ");
        total_rows = scanner.nextInt();

        // looping for rows
        for (row = 1; row <= total_rows; row++) {

            //looping to print fro 1 to mid value
            for (valup = 1; valup <= row; valup++) {
                System.out.print(valup);
            }

            // looping to print from one after the mid value to 1
            for (valdown = row-1; valdown >= 1; valdown--) {
                System.out.print(valdown);
            }
            System.out.println();
        }
    }

}
