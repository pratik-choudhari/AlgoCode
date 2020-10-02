import java.util.*;git 

public class Pth term {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println(" *** Gives the pth term of an AP when mth and nth term are inserted ***   ");
        System.out.print("Enter the term : ");
        int m = sc.nextInt();
        System.out.print("Enter the value of "+m+"th term : ");
        int mvalue = sc.nextInt();
        System.out.print("Enter the term : ");
        int n = sc.nextInt();
        System.out.print("Enter the value of "+n+"th term : ");
        int nvalue = sc.nextInt();
        System.out.print("Enter the term for which you want the value : ");
        int term = sc.nextInt();

        int first_term,common_difference,term_value;
        common_difference = (mvalue - nvalue) / (m -n);
        first_term = ((1 - n) * mvalue + (m - 1) * nvalue)/(m-n) ;
        
        term_value = first_term + (term - 1 ) * common_difference ; 
        System.out.println("The value of "+term+"th term is "+term_value+".");

        sc.close();
    }
    
}
