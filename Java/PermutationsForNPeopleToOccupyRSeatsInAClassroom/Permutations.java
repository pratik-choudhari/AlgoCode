import java.util.Scanner;
public class Permutations
{
    public static void main(String[] args) 
    {
        int n, ans ,r;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the num of people: ");
        n = s.nextInt();
		System.out.print("Enter the number of seats available: ");
		r = s.nextInt();
        Permutations obj = new Permutations();
        ans = obj.fact(n)/obj.fact(n-r);
        System.out.println("\nNum of ways people can be seated: "+ans);
    }
    int fact(int x)
    {
        if(x > 1)
        {
            return(x * fact(x - 1));
        }
        return 1;
    }
}