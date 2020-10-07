//Given a string of words with lots of spaces between the words , remove all the unnecessary spaces.

//Example

//input: I______live_____on_____earth

//Underscore( _ ) here are actually white spaces i used underscore to reprensent white space because Github is also omitting
//the extra spaces between the input string mentioned above ;) Just seen real world example of this question while writing it.

//output: I live on earth

//@author: sushant19-99

import java.io.*;
public class RemoveExtraSpace 
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter the string from which extra space needs to be removed \n");
		String str=br.readLine();

	        //this replaces one or more whitespaces with a single whitespace
		str=str.replaceAll("\\s+"," ");
  
	        // trim function removes any extra space at the begining or the end of the string
		str=str.trim();
   
	        System.out.println(str);
	}
}
