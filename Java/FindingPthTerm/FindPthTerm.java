package algoCode;

import java.util.Scanner;

public class FindPthTerm {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n, m, Tm, Tn, p, Tp;
		Scanner sc = new Scanner(System.in);

		// Taking n, m, p, nth term, mth term from user
		System.out.print("Enter term numbers (n) & (m) : ");
		n = sc.nextInt();
		m = sc.nextInt();
		System.out.println();
		System.out.print("Enter nth and mth terms : ");
		System.out.println();
		Tn = sc.nextInt();
		Tm = sc.nextInt();
		System.out.print("Enter term number(p) : ");
		System.out.println();
		p = sc.nextInt();

		// Calculating value of d
		int d = (Math.abs(Tm - Tn)) / Math.abs((m - 1) - (n - 1));

		// Calculating value of a
		int a = Tm - ((m - 1) * d);

		// Calculation pth term
		Tp = a + (p - 1) * d;

		System.out.println(p + "th term is : " + Tp);

	}

}
