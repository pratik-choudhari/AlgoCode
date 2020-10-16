import java.util.*;
public class HelloWorld {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] ar_first = new int[n/2+1];
		int[] ar_second = new int[n];
		for(int i=0;i<n;i++) {
			int p = s.nextInt();
			if(i<n/2)ar_first[i]=p;
			else ar_second[i]=p;
		}
		Arrays.sort(ar_first);
		Arrays.sort(ar_second);
		for(int i=1;i<=n/2;i++) {
			System.out.print(ar_first[i]+" ");
		}
		for(int i=n-1;i>=n/2;i--) {
			 System.out.print(ar_second[i]+" ");
		}
	}

}