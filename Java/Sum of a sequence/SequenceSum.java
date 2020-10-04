import java.util.Scanner;
public class SequenceSum {
	public static void main(String[] args) {
		Scanner sn=new Scanner(System.in);
		System.out.println("Enter Sequence limit");
		int n=sn.nextInt();
		int sum=0;
	  System.out.print("Sequence: ");
		for(int i=1;i<=n;i++) {
			int term=(i*i)-(i-1)*(i-1);
			System.out.print(term+" ");
			sum=sum+term;
		}
		System.out.println();
		System.out.println("Sum: "+sum);

	}

}
