import java.io.*;
import java.lang.*;
class Convert
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
public static void main(String args[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
Convert o=new Convert();
double m;
int num,n,d,octal;
String s,h;
do
    {
        System.out.println("\n1.Decimal to Binary\t 2.Decimal to Hexadecimal\t 3.Decimal to octal\n 4.Binary to Decimal\t 5.Binary to Hexadecimal\t 6.Binary to octal\n 7.Hexadecimal to Decimal\t 8.Hexadecimal to Binary\t 9.Hexadecimal to Octal\n 10.Octal to Decimal\t 11.Octal to Binary\t 12.Octal to Hexadecimal\n 13.Exit\n");
        System.out.println("Enter your choice:");
        n=Integer.parseInt(br.readLine());
        switch(n)
        {
            case 1:System.out.println("Enter a Decimal number:");
                    m=Double.parseDouble(br.readLine());
                    num=(int)m;
                    s=o.dec_bin(num,m-num);
                    System.out.println("Binary number is:"+s);
                    break;
            case 2:System.out.println("Enter a Decimal number:");
                    m=Double.parseDouble(br.readLine());
                    num=(int)m;
                    o.decToHex(num);
                    break;
            case 3: System.out.println("Enter a Decimal number:");
                    m=Double.parseDouble(br.readLine());
                    num=(int)m;
                    o.decToOctal(num);
                    break;
            case 4: System.out.println("Enter a Binary number:");
                    num=Integer.parseInt(br.readLine());
                    d= o.binaryToDecimal(num);
                    System.out.println("Decimal number is:"+d);
                    break;
            case 5:System.out.println("Enter a Binary number:");
                    num=Integer.parseInt(br.readLine());
                    d= o.binaryToDecimal(num);
                    o.decToHex(d);
                    break;
            case 6: System.out.println("Enter a Binary number:");
                    num=Integer.parseInt(br.readLine());
                    d=o.binaryToDecimal(num);
                    o.decToOctal(d);
                    break;
            case 7:System.out.println("Enter a Hexadecimal number:");
                    h=br.readLine();
                    d=o.hexa_Dec(h);
                    System.out.println("Decimal number is:"+d);
                    break;
            case 8:System.out.println("Enter a Hexadecimal number:");
                    h=br.readLine();
                    d=o.hexa_Dec(h);
                    num=(int)d;
                    s=o.dec_bin(num,d-num);
                    System.out.println("Binary number is:"+s);
                    break;
            case 9:System.out.println("Enter a Hexadecimal number:");
                    h=br.readLine();
                    d=o.hexa_Dec(h);
                    o.decToOctal(d);
                    break;
            case 10:System.out.println("Enter a Octal number:");
                    octal=Integer.parseInt(br.readLine());
                    d=o.Octal_Dec(octal);
                    System.out.println("Decimal number is:"+d);
                    break;
            case 11:System.out.println("Enter a Octal number:");
                    octal=Integer.parseInt(br.readLine());
                    d=o.Octal_Dec(octal);
                    num=(int)d;
                    s=o.dec_bin(num,d-num);
                    System.out.println("Binary number is:"+s);
                    break;
            case 12:System.out.println("Enter a Octal number:");
                    octal=Integer.parseInt(br.readLine());
                    d=o.Octal_Dec(octal);
                    o.decToHex(d);
                    break;
            case 13: break;
            default: System.out.println("INVALID CHOICE");
        }
    }while(n!=13);
}

  public int binaryToDecimal(int n)
    {
        int num = n;
        int dec_value = 0;
        int base = 1;
        int temp = num;
        while (temp > 0)
        {
            int rem = temp % 10;
            temp = temp / 10;
            dec_value += rem * base;
            base = base * 2;
        }
        return dec_value;
    }

  public String dec_bin(int n,double num)
    {
        String s1="",s2="";
        int rem;
        if(n<0)
        {
            n=-n;
            num=-num;
        }
        if(n==0)
        {
            s1=s1+n;
        }
        else
        {
            while(n!=0)
            {
                rem=n%2;
                s1=s1+rem;
                n=n/2;
            }
        }
        StringBuffer temp=new StringBuffer(s1);
        temp.reverse();
        s1=temp.toString();
        int net,count=0;
        while(count!=10)
        {
            num=num*2;
            if(num>=1)
            {
                s2=s2+"1";
                num=num-1;
            }
            else
            {
                s2=s2+"0";
            }
            count++;
        }
        String s;
        s=s1+"."+s2;
        return s;
    }

 public void decToHex(int n)
    {
        char[] hexa = new char[100];
        int i = 0;
        while(n!=0)
        {
            int temp  = 0;
            temp = n % 16;
            if(temp < 10)
            hexa[i] = (char)(temp + 48);
            else
            hexa[i] = (char)(temp + 55);
            i++;
            n = n/16;
        }
        System.out.println("Hexadecimal number is:");
        for(int j=i-1; j>=0; j--)
            System.out.print(hexa[j]);
    }

    public void decToOctal(int n)
    {
        int[] octal = new int[100];
        int i = 0;
        while (n != 0)
        {
            octal[i] = n % 8;
            n = n / 8;
            i++;
        }
        System.out.println("Octal number is:");
        for (int j = i - 1; j >= 0; j--)
            System.out.print(octal[j]);
    }

  public int hexa_Dec(String h)
    {
        int base = 1;
        int dec = 0;
        for (int i=h.length()-1; i>=0; i--)
        {
            if (h.charAt(i) >= '0' && h.charAt(i) <= '9')
                dec += (h.charAt(i) - 48)*base;
            else if (h.charAt(i) >= 'A' && h.charAt(i) <= 'F')
                dec += (h.charAt(i) - 55)*base;
            base = base*16;
        }
        return dec;
    }

    public int Octal_Dec(int octal)
    {
        int dec = 0, i = 0;
        while(octal != 0)
        {
            dec += (octal % 10) * Math.pow(8, i);
            i++;
            octal/=10;
        }
        return dec;
    }

}
