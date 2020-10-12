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
                        Console.WriteLine(BinToDec(num));
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        Console.WriteLine(DecToBin(int.Parse(num)));
                        break;
                    case 5:
                        Console.WriteLine(DecToOct(int.Parse(num)));
                        break;
                    case 6:
                        Console.WriteLine(DecToHex(int.Parse(num)));
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    case 9:
                        break;
                    case 10:
                        break;
                    case 11:
                        break;
                    case 12:
                        break;
                }
                Console.WriteLine();
                Console.Write("Please select a program: ");
                program = int.Parse(Console.ReadLine());
            }
        }
        public static string DecToBin(int dec){
            string revbin = "";
            while (dec>0){
                revbin += (dec % 2).ToString();
                dec /= 2;
            }
            string bin = "";
            for (int i = revbin.Length - 1; i >= 0;i--){
                bin += revbin[i];
            }
            return bin;
        }
        public static string DecToOct(int dec){
            string revbin = "";
            while (dec>0){
                revbin += (dec % 8).ToString();
                dec /= 8;
            }
            string oct = "";
            for (int i = revbin.Length - 1; i >= 0;i--){
                oct += revbin[i];
            }
            return oct;
        }
        public static string DecToHex(int dec){
            string revbin = "";
            string[] hexdict = new string[16] { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
            while (dec>0){
                revbin += hexdict[(dec % 16)];
                dec /= 16;
            }
            string hex = "";
            for (int i = revbin.Length - 1; i >= 0;i--){
                hex += revbin[i];
            }
            return hex;
        }
        
        
        public static double BinToDec(string bin){
            double value = 0;
            for (int i=bin.Length-1; i>=0; i--){
                value += (bin[i]-'0')* Math.Pow(2.0,(bin.Length-i-1));
            }
            return value;
        }
        
    }
}
