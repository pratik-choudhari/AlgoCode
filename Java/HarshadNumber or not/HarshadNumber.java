import java.util.*;

public class HarshadNumber{
    //take input from user
    int input;
    HarshadNumber(int input){
        this.input = input;
    }
    //method to check given number is Harshad or not
    private boolean isHarshadNumber(){
        String string_input = String.valueOf(input);
        int sum = 0,result = 0;
        if(string_input.equals("0")){
        	return false;
        }
        for(int i = 0;i < string_input.length();i++)
        {
            sum += Character.getNumericValue(string_input.charAt(i));
        }
        result = input % sum;
        if(result == 0) {
        	return true;
        }  
        return false;
    }
    public static void main(String args[]){
        Scanner scan = null;
    	try{
        	scan = new Scanner(System.in);
        }catch(Exception e) {
        	System.out.println(e.toString());
        }
        int in = scan.nextInt();
        HarshadNumber n = new HarshadNumber(in);
        if(n.isHarshadNumber()){
            System.out.println(in + " is HarshadNumber");
        }
        else{
            System.out.println(in + " is not HarshadNumber");
        }  
    }
}