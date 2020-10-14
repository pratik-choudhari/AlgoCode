using System;

namespace max_num_handshakes
{
    public class Test
    {
	    public static void Main()
	    {
    	    int num_people;//Variable defination
    	    Console.Write("Enter the number of people: ");
    	    num_people = Convert.ToInt32(Console.ReadLine());//Taking input and explicitly converting the input to int
    	    int num_handshakes;
    	    num_handshakes = num_people * (num_people-1)/2;
    	    Console.Write("Maximum Number of Hanshakes will be: ");
    	    Console.WriteLine(num_handshakes);
	    }
    }
}