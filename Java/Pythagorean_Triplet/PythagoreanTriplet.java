import java.io.BufferedReader;
import java.io.InputStreamReader;
 
public class PythagoreanTriplet {
    // Function to find and display Pythagorean triplets
    static void printPythagoreanTriplets(int[] array){
        int i,j,k;
        int x,y,z;
        int count=0;
        for(i=0;i<array.length;i++){
            x=array[i];
            for(j=0;j<array.length;j++){
                y=array[j];
                for(k=0;k<array.length;k++){
                    z=array[k];
                    if((z*z)==(x*x + y*y)){
                        count++;
                        System.out.print4("Pythagorean Triplets:");
                        System.out.println(x+", "+y+", "+z);
                        return;
                    }
                }
            }
        }
        System.out.println("No pythagorean triplets exist in the array");
    }
    // Function to read user input
    public static void main(String[] args) {
        int size;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the array size");
        try {
            size = Integer.parseInt(br.readLine());
        } catch (Exception e) {
            System.out.println("Invalid Size");
            return;
        }
        int[] array = new int[size];
        int i;
        System.out.println("Enter array elements");
        for (i = 0; i < array.length; i++) {
            try {
                array[i] = Integer.parseInt(br.readLine());
            } catch (Exception e) {
                System.out.println("An error occurred");
            }
        }
        printPythagoreanTriplets(array);
    }
}