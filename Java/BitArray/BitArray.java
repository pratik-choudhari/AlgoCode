public class BitArray {

    // The bit array
    private int[] a;

    // Number of elements in the bit array
    private int N;

    /**
     * Constructs the bit array according to the pseudo code in Issue #405
     */
    public BitArray(int N, int S, int P, int Q) {
        this.N = N;
        this.a  = new int[N];

        // Implementing the pseudo code
        a[0] = S % (int) Math.pow(2, 31);
        for (int i = 1; i < N; i++) {
            a[i] = (a[i - 1] * P) + (Q % (int) Math.pow(2, 31));
        }
    }

    /**
     * Calculates the number of distinct elements in array a
     *
     * @return number of distinct elements as int
     */
    public int countDistinct() {
        // At least one distinct element
        int num = 1;

        // Iterate over every element except the first
        for (int i = 1; i < this.N; i++) {
            int j;

            // Iterate over all elements up to element i
            for (j = 0; j < i; j++)
                if (this.a[i] == this.a[j])
                    // Element i and j are equal, hence no new distinct element
                    break;

            if (i == j)
                // Element i is distinct
                num++;
        }
        return num;
    }

    /**
     * Prints the bit array
     *
     * @return Bit array as String
     */
    @Override public String toString() {
        // Build the String
        String s = "Bit array: [";
        for (int i : this.a) {
            s += i + ",";
        }
        return s.substring(0, s.length() - 1) + "]";
    }

    /**
     * Simple client function, reading the user input and calling countDistinct()
     */
    public static void main(String[] args) {
        // Check validity of arguments
        if (args.length != 4) {
            throw new IllegalArgumentException("Number of arguments must be 4, but is " + args.length + ".");
        }

        // Read arguments
        int N = Integer.parseInt(args[0]);
        int S = Integer.parseInt(args[1]);
        int P = Integer.parseInt(args[2]);
        int Q = Integer.parseInt(args[3]);

        // Create instance of BitArray
        BitArray bitArray = new BitArray(N, S, P, Q);

        // Optionally: Print the bit array
        // System.out.println(bitArray);

        // Print number of distinct elements
        System.out.println(bitArray.countDistinct());
    }
}
