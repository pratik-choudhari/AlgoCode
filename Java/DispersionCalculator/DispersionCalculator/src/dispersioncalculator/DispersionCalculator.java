/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dispersioncalculator;

import java.util.Scanner;

/**
 *
 * @author Alex
 */
public class DispersionCalculator {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        System.out.println("Input: ");
        String data = sc.nextLine();
        String[] dataset = data.split(",");
        System.out.println(range(dataset));
        System.out.println(variance(dataset));
        System.out.println(standardDeviation(dataset));
    }
    
    public static double range(String[] dataset)
    {
        double min = Double.MAX_VALUE;
        double max = 0;
        for(String datum : dataset)
        {
            double doubleDatum = Double.parseDouble(datum);
            if(doubleDatum < min)
            {
                min = doubleDatum;
            }
            else if(doubleDatum > max)
            {
                max = doubleDatum;
            }
        }
        return max-min;
    }

    private static double variance(String[] dataset) {
        int n = dataset.length;
        double sum = 0;
        double sumSquares = 0;
        for(String datum : dataset)
        {
            double doubleDatum = Double.parseDouble(datum);
            sum += doubleDatum;
            sumSquares += (doubleDatum * doubleDatum);
        }
        double variance = (sumSquares/n)-(sum/n)*(sum/n);
        return variance;
    }

    private static double standardDeviation(String[] dataset) {
        return Math.sqrt(variance(dataset));
    }
    
}
