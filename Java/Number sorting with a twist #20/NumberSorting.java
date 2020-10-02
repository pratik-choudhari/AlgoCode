import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
public  class FibinacciSeries //Name of the class
{	
	   static class FastReader 
	    { 
	        BufferedReader br; 
	        StringTokenizer st; 
	       
	  
	        public FastReader() 
	        { 
	            br = new BufferedReader(new
	                     InputStreamReader(System.in)); 
	        } 
	  
	        String next() 
	        { 
	            while (st == null || !st.hasMoreTokens()) 
	            { 
	                try
	                { 
	                    st = new StringTokenizer(br.readLine()); 
	                } 
	                catch (IOException  e) 
	                { 
	                    e.printStackTrace(); 
	                } 
	            } 
	            return st.nextToken();
	            
	        } 
	  
	        int nextInt() 
	        { 
	            return Integer.parseInt(next()); 
	        } 
	  
	        long nextLong() 
	        { 
	            return Long.parseLong(next()); 
	        } 
	  
	        double nextDouble() 
	        { 
	            return Double.parseDouble(next()); 
	        } 
	  
	        String nextLine() 
	        { 
	            String str = ""; 
	            try
	            { 
	                str = br.readLine(); 
	            } 
	            catch (IOException e) 
	            { 
	                e.printStackTrace(); 
	            } 
	            return str; 
	        }

			public Character charAt(int i) {
				// TODO Auto-generated method stub
				return null;
			}

			public BigInteger nextBigInteger() {
				// TODO Auto-generated method stub
				return null;
			} 
	    } 

	public static void main(String[] args) throws IOException {
    	FastReader s=new FastReader();
			int n = s.nextInt();
			int[] ar = new int[n];
			int[] t = new int[n];
			int c=0;
			for(int i=0;i<n;i++) {
				ar[i]=s.nextInt();
				if(i>0 && ar[i]>=ar[i-1])c++;
			}
			System.out.println(c>0?"YES":"NO");
	}
		
    
}	
  	