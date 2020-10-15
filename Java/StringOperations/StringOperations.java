package StringOperations;

import java.util.*;
import java.io.*; 

public class StringOperations {

    public static void main(String[] args){

      String[] menulist = new String[10];
      int i;
      int n = 0;
      int status = 1;
      String inputstr;
      String substring1;
      String substring2;
      String replacedstr;
      String concatenatestr;
      Scanner in = new Scanner(System.in);
      Scanner in2 = new Scanner(System.in);
      Scanner in3 = new Scanner(System.in);
      Scanner in4 = new Scanner(System.in);
      Scanner in5 = new Scanner(System.in);

      menulist[0] = "String Length";
      menulist[1] = "Count number of vowels";
      menulist[2] = "Check if the string is Palindrome";
      menulist[3] = "Remove Vowels from the string";
      menulist[4] = "Calculate the frequency of characters in the string";
      menulist[5] = "Replace substring in a string";
      menulist[6] = "Remove spaces from the string";
      menulist[7] = "Capitalize the first and last character of each word in the string";
      menulist[8] = "Count the sum of numbers in a string";
      menulist[9] = "Concatenate with another input string";

      System.out.println("Select the string operation you would like to perform by entering the number assigned the operation");
      System.out.println("------------------------------");   
      for (i = 0; i < menulist.length; i++) { 
      // accessing each element of array
      System.out.println(i + ".  " + menulist[i]); 
        } 
      System.out.println("------------------------------");   
       // get  menu selection input 
      
      while (status==1) {
      n = in.nextInt();
      if (n<0 || n>9){      
        System.out.println("Please neter a valid number between 0 and 9");
        n = in.nextInt();}
      status = 0;
      }

      System.out.println("The operation requested is : "+ menulist[n] );

      System.out.println("------------------------------");  
      System.out.println("Please enter the string : "); 
      inputstr = in2.nextLine(); // get  input string 
      System.out.println("------------RESULT------------------");
      switch (n) {
          case 0:
            System.out.println(menulist[n]+" : "+inputstr.length());
            break;
          case 1:
            System.out.println(menulist[n]+" : "+countVowels(inputstr));
            break;
          case 2:
            System.out.println(menulist[n]+" : "+isPalindrome(inputstr));
            break;
          case 3:
            System.out.println(menulist[n]+" : "+removeVowel(inputstr));
            break;
          case 4:
            System.out.println(menulist[n]+" : ");
            characterCount(inputstr);
            break;
          case 5:
            System.out.println("Enter the substring to be replaced");
            substring1 = in3.nextLine(); // get  input string 
            System.out.println("Enter the text to be replaced with");
            substring2 = in4.nextLine(); // get  input string 
            replacedstr = inputstr.replace(substring1, substring2);
            System.out.println(menulist[n]+" : "+replacedstr);
            break;
          case 6:
            System.out.println(menulist[n]+" : "+inputstr.replaceAll("\\s", ""));
            break;
          case 7:
            System.out.println(menulist[n]+" : "+capitalizeFirstLast(inputstr));
            break; 
          case 8:
            System.out.println(menulist[n]+" : "+numberSum(inputstr));
            break;   
          case 9:
            System.out.println("Enter the string to concatenate with");
            concatenatestr = in5.nextLine(); ;
            System.out.println(menulist[n]+" : "+inputstr+concatenatestr);
            break;                        
        }

      in.close ();
      in2.close ();      
      in3.close ();
      in4.close ();
      in5.close ();

    }
    /***Count vovels***/
 public static int countVowels(String str)
    {
        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i'
                    || str.charAt(i) == 'o' || str.charAt(i) == 'u')
            {
                count++;
            }
        }
        return count;
    }
    /**Check if Palindrome***/
  public static String isPalindrome(String str) 
    { 
        int i = 0, j = str.length() - 1; 
        while (i < j) { 
            if (str.charAt(i) != str.charAt(j)) 
                return "False"; 
            i++; 
            j--; 
        } 
        return "True"; 
    } 
  /**remove vovels**/
    public static String removeVowel(String str) 
    { 
         Character vowels[] = {'a', 'e', 'i', 'o', 'u','A','E','I','O','U'}; 
           
         List<Character> al = Arrays.asList(vowels); 
           
         StringBuffer sb = new StringBuffer(str); 
           
         for (int i = 0; i < sb.length(); i++) { 
              
             if(al.contains(sb.charAt(i))){ 
                sb.replace(i, i+1, "") ; 
                i--; 
             } 
        } 
      return sb.toString(); 
    }
    //Calculate the frequency of characters in the string
    public static void characterCount(String inputString) 
    { 
        HashMap<Character, Integer> charCountMap 
            = new HashMap<Character, Integer>(); 
          char[] strArray = inputString.toCharArray(); 
        for (char c : strArray) { 
            if (charCountMap.containsKey(c)) { 
                charCountMap.put(c, charCountMap.get(c) + 1); 
            } 
            else { 
                charCountMap.put(c, 1); 
            } 
        } 
        for (Map.Entry entry : charCountMap.entrySet()) { 
            System.out.println(entry.getKey() + " " + entry.getValue()); 
        } 
    } 
    //capitalize
    public static String capitalizeFirstLast(String str) 
    {  
        char[] ch = str.toCharArray(); 
        for (int i = 0; i < ch.length; i++) { 
            int k = i; 
            while (i < ch.length && ch[i] != ' ') 
                i++; 
            ch[k] = (char)(ch[k] >= 'a' && ch[k] <= 'z'
                               ? ((int)ch[k] - 32) 
                               : (int)ch[k]); 
            ch[i - 1] = (char)(ch[i - 1] >= 'a' && ch[i - 1] <= 'z'
                                   ? ((int)ch[i - 1] - 32) 
                                   : (int)ch[i - 1]); 
        } 
        return new String(ch); 
    } 
    //sum of numbers
    public  static int numberSum(String str)  
    {  
        char[] c = str.toCharArray();
        int sum = 0;

        for(int i = 0;i<=c.length-1;i++)
        {
          if(Character.isDigit(c[i]))
          {
              Character c1 = c[i];
              String s1 = c1.toString();
              int i1 = Integer.parseInt(s1);

              sum = sum+i1;
          }
        }
        return sum;  
    } 
  

}
