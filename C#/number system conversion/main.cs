using System;

namespace number_system_conversion
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(@"Menu: 
            1.Binary to Decimal
            2.Binary to Octal
            3.Binary to Hexadecimal
            4.Decimal to Binary
            5.Decimal to Octal
            6.Decimal to Hexadecimal
            7.Octal to Binary
            8.Octal to Decimal
            9.Octal to Hexadecimal
            10.Hexadecimal to Binary
            11.Hexadecimal to Octal
            12.Hexadecimal to Decimal
            13.Exit
            ");
            Console.Write("Please select a program: ");
            int program = int.Parse(Console.ReadLine());
            while(program>0&&program<13)
            {
                Console.Write("Great! Select a number: ");
                string num=Console.ReadLine();
                switch(program){
                    case 1:
                        BinToDec(num);
                        break;
                    
                }
                Console.WriteLine();
                Console.Write("Please select a program: ");
                program = int.Parse(Console.ReadLine());
            }
        }
        public static void BinToDec(string bin){
            double value = 0;
            for (int i=bin.Length-1; i>=0; i--){
                value += (bin[i]-'0')* Math.Pow(2.0,(bin.Length-i-1));
            }
            Console.WriteLine(value+"");
        }
    }
}
