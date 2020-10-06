import java.util.*;
public class SequenceSum {
	public static void main(String[] args) {
		Scanner sn=new Scanner(System.in);
		System.out.println("Enter Sequence limit");
		int n=sn.nextInt();//taking limit of sequence as an input
		int sum=0;
	  System.out.print("Sequence: ");
		for(int i=1;i<=n;i++) {
			int term=(i*i)-(i-1)*(i-1);//calculating each term of sequence
			System.out.print(term+" ");//printing elements of sequence
			sum=sum+term;//calculate sum of sequence
		}
		System.out.println();
		System.out.println("Sum: "+sum);//printing sum of sequence

	}

}
