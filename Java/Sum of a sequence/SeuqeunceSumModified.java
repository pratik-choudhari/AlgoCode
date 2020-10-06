import java.util.Scanner;
public class SeuqeunceSumModified {
    public static void main(String[] args) {
		Scanner sn=new Scanner(System.in);
		System.out.println("Enter Sequence limit");
        int n=sn.nextInt();//taking limit of sequence as an input
        sn.close();
		
	   System.out.print("Answer: "+(n*n));
		
	}
}

//taking example of 3 ,,, (3^2 - 2^2)+(2^2-1^2)+(1^2-0^2) rordering it and we get
//                        (3^2) -( 2^2 -2^2)-(1^2 -1^2)-(0^2) all cancels out and 3^2 is left
