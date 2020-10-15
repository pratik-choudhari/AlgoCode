import java.util.*;
public class HelloWorld {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		List<Integer> ar = new ArrayList<>();
		int[] frequency = new int[100000000];
		long sum=0, even=0,odd=0,repeated=0,distinct=0;
		
		for(int i=0;i<n;i++) {
			int p = s.nextInt();
			if(ar.contains(p))repeated++;
			else{
				distinct++;
			}
			ar.add(p);
			frequency[p]++;
			sum+=ar.get(i);
			if(ar.get(i)%2==0)even++;
			else odd++;
			
		}
		List<Integer> temp = new ArrayList<>();
		Collections.sort(ar);
		System.out.println("Smallest Number: "+ar.get(0));
		System.out.println("Largest  Number: "+ar.get(n-1));
		System.out.println("Sum of Array elements = "+sum);
		for(int i=0;i<n;i++) {
			
						if(!temp.contains(ar.get(i)) && frequency[ar.get(i)]!=0) {
							if(i==n-1)System.out.print(ar.get(i)+"-"+frequency[ar.get(i)]);
							else System.out.print(ar.get(i)+"-"+frequency[ar.get(i)]+",");
							temp.add(ar.get(i));
						}
		}
		System.out.println();
		
		System.out.println("Count of distinct elements="+distinct);
		System.out.println("Count of repeating elements="+repeated);
		System.out.println("Count of Even Elements ="+even);
		System.out.println("Count of odd Elements = "+odd);
	}

}