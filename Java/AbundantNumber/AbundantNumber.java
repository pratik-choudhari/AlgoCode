import java.util.Scanner;

class AbundantNumber{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number");
        long num=sc.nextLong(); //Input Number
        int sum=1; // stores the sumof the perfect factors
        for(int i=2;i<=(int)Math.sqrt(num);i++){ 
            if(num%i==0 )
                sum+=num/i+i;
        }
        if(num>=sum)
            System.out.println("The number is Not an Abundant Number !!");
        else    
            System.out.println("The number is an Abundant Number");
    }
}