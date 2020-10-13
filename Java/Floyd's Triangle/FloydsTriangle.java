public class FloydsTriangle {


  /**
   * Main argument that attempts to parse command line arguments as input,
   * then calls the outputFloydsTriangle method to demonstrate functionality.
   * If nothing is input or its invalid, it will run with a default row
   * amount of 5.
   *
   * @param args  The arguments to main, if an integer is input it will be the number of rows
   *              in the outputted Floyd's Triangle.
   */
  public static void main( String[] args ) {
    int rows = 5;

    // if there's a command line argument, attempt to use it in method call
    if (args.length >= 1) {

      // catch errors if its not an integer
      try {
        rows = Integer.parseInt( args[0] );
      } catch (Exception e) {
        throw new IllegalArgumentException( "You must input an integer as an argument!" );
      }
    }

    // output the result to the user
    System.out.println( outputFloydsTriangle( rows ) );

  }



  // static private method to actually create the floyd's triangle, called in main
  private static String outputFloydsTriangle( int rows ) {

    // initialize a string builder for efficiency and give it a starting message.
    StringBuilder sb =
            new StringBuilder( String.format( "\nFloyd's Triangle for %s rows is:\n\n", rows ));

    // initialize starting variable
    int count = 1;

    // forloop to give requisite number of rows
    for (int i = 0; i < rows; i++) {

      // for loop to give requisite digits in each row
      for (int j = 0; j < i+1; j++ ) {

        if (j != 0) {
          sb.append( " " ); // append a space if this is not the first digit
        }
        sb.append( count ); // append the current number
        count++;            // increment the number
      }
      sb.append( "\n");     // once the numbers for this row are done, add newline
    }

    // return the stringbuilder object's String
    return sb.toString();

  }


}
