/*
 * Tower of Hanoi
*/
import java.util.Scanner;
import java.lang.Math; 

public class TowerOfHanoi {
    
    static void tower(int a, String from, String aux, String to) {
        if(a == 1) {
            System.out.println("Move Disk 1 from " + from + " to " + to);
            return;
        } else {
            tower(a-1, from, to, aux);
            System.out.println("Move Disk " + a + " from " + from + " to " + to);
            tower(a-1, aux, from, to);
        }
    }
	
	public static void main (String[] args) {
		Scanner scannerObj = new Scanner(System.in);
		String[] values = scannerObj.nextLine().split(" ");
		int n = Integer.parseInt(values[0]);
		tower(n, values[1], values[2], values[3]);
		System.out.println("It took " + (int) (Math.pow(2, n)-1) + " steps in total");
		
	}
}

