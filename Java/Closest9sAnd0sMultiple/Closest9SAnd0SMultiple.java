/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package closest.pkg9.s.and.pkg0.s.multiple;

/**
 *
 * @author Alex
 */
import java.util.*;
public class Closest9SAnd0SMultiple {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Please enter a postitive integer: ");
        long n = sc.nextLong();
        
        LinkedList<Long> numberSet = generate90numbers(n);
        long smallestMultiple = findSmallestMultiple(n,numberSet);
        System.out.println("The smallest multiple of: " + n + " That only contains 9s and 0s is: " + smallestMultiple);
    }
    
    public static LinkedList<Long> generate90numbers(long n) //method to build and return a list of all numbers up to a limit that consist of 9s and 0s
    {
        long MAX_COUNT = 100000;
        LinkedList<String> numberBuildingList = new LinkedList<>();
        LinkedList<Long> finalList = new LinkedList<>();
        numberBuildingList.add("9");
        for(int i  = 0; i < MAX_COUNT; i++)
        {
            String numInList = numberBuildingList.poll();
            numberBuildingList.add(numInList + "0");
            numberBuildingList.add(numInList + "9");
            finalList.add(Long.parseLong(numInList));
        }
        return finalList;
    }
    
    public static long findSmallestMultiple(long number, LinkedList<Long> numbersToCompare) //compare all numbers generated with the desired number to find a multiple
    {
        for(long possibleMultiple : numbersToCompare)
        {
            if(possibleMultiple % number == 0)
            {
                return possibleMultiple;
            }
        }
        return -1; //no result found - most likely a result of an input too great
    }
    
    
}
