import java.util.*;
import java.io.*;
public class CountSingleDigits { 
    static int singleOccurence(int[] arr) 
    { 
        int n = arr.length;
        int count =0;
        HashMap<Integer, Integer> mp = new HashMap<>(); 

        for (int i = 0; i < n; i++)  
        { 
            if (mp.containsKey(arr[i])) 
                mp.put(arr[i], 1 + mp.get(arr[i])); 
            else
                mp.put(arr[i], 1); 
        } 

        for (Map.Entry entry : mp.entrySet())  
        { 
            if (Integer.parseInt(String.valueOf(entry.getValue())) == 1)                     
                count++; 
        } 
        return count;
    } 

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Input: ");
        String inputString = br.readLine();
        int[] inputArray = new int[inputString.length()];
        for(int i=0;i<inputString.length();i++)
            inputArray[i] = inputString.charAt(i) - '0';
        int count = singleOccurence(inputArray);
        System.out.println("Output: "+count);
    }
} 