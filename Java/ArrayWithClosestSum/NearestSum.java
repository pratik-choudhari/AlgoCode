package algoCode;

import java.util.Arrays;
import java.util.Scanner;

public class NearestSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		int n;
		System.out.println("Enter number of elements in the array: ");
		n = sc.nextInt(); // input number of elements
		int[] Array = new int[n];

		// Taking array from the user
		System.out.println("Enter array elements:");
		for (int i = 0; i < n; i++) {
			Array[i] = sc.nextInt();
		}

		// finding sum of elements of array
		int sum = 0;
		for (int k : Array)
			sum += k;

		// finding average
		int avg = sum / n;

		// For sum to greater than initial sum, all the elements should be greater than
		// average number
		int minVal = avg + 1;

		// modifying array
		for (int i = 0; i < n; i++) {
			Array[i] = minVal;
		}

		int result = minVal * n;

		System.out.println("Modified Array:" + Arrays.toString(Array));
		System.out.println("Sum: " + result);

	}

}
