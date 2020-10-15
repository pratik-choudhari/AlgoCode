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

            int count = 0;
            int program = 0;
            int maxTries = 3;
            do
            {
                count = 0;
                maxTries = 3;
                while (count < maxTries)
                {
                    try
                    {
                        Console.Write("Please select a program: ");
                        program = int.Parse(Console.ReadLine());
                        break;
                    }
                    catch (FormatException e)
                    {
                        Console.WriteLine("Please Enter a number!");
                        if (++count >= maxTries) throw e;
                    }
                }

                Console.Write("Great! Select a number: ");
                string num = Console.ReadLine();
                if (num == "")
                    continue;
                switch (program)
                {
                    case 1:
                        Console.WriteLine(BinToDec(num));
                        break;
                    case 2:
                        Console.WriteLine(DecToOct(BinToDec(num)));
                        break;
                    case 3:
                        Console.WriteLine(DecToHex(BinToDec(num)));
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
                        Console.WriteLine(DecToBin(OctToDec(num)));
                        break;
                    case 8:
                        Console.WriteLine(OctToDec(num));
                        break;
                    case 9:
                        Console.WriteLine(DecToHex(OctToDec(num)));
                        break;
                    case 10:
                        Console.WriteLine(DecToBin(HexToDec(num)));
                        break;
                    case 11:
                        Console.WriteLine(DecToOct(HexToDec(num)));
                        break;
                    case 12:
                        Console.WriteLine(HexToDec(num));
                        break;
                }
                Console.WriteLine();
            } while (program > 0 && program < 13);
        }
        //Convertions from Decimal To X
        public static string DecToBin(int dec)
        {
            string revbin = "";
            while (dec > 0)
            {
                revbin += (dec % 2).ToString();
                dec /= 2;
            }
            string bin = "";
            for (int i = revbin.Length - 1; i >= 0; i--)
            {
                bin += revbin[i];
            }
            return bin;
        }
        public static string DecToOct(int dec)
        {
            string revbin = "";
            while (dec > 0)
            {
                revbin += (dec % 8).ToString();
                dec /= 8;
            }
            string oct = "";
            for (int i = revbin.Length - 1; i >= 0; i--)
            {
                oct += revbin[i];
            }
            return oct;
        }
        public static string DecToHex(int dec)
        {
            string revbin = "";
            string[] hexdict = new string[16] { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
            while (dec > 0)
            {
                revbin += hexdict[(dec % 16)];
                dec /= 16;
            }
            string hex = "";
            for (int i = revbin.Length - 1; i >= 0; i--)
            {
                hex += revbin[i];
            }
            return hex;
        }

        //Convertions from X to Decimal
        public static int BinToDec(string bin)
        {
            int value = 0;
            for (int i = bin.Length - 1; i >= 0; i--)
            {
                value += (int)((bin[i] - '0') * Math.Pow(2.0, (bin.Length - i - 1)));
            }
            return value;
        }
        public static int OctToDec(string oct)
        {
            int value = 0;
            for (int i = oct.Length - 1; i >= 0; i--)
            {
                value += (int)((oct[i] - '0') * Math.Pow(8.0, (oct.Length - i - 1)));
            }
            return value;
        }
        public static int HexToDec(string hex)
        {
            string[] hexdict = new string[16] { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
            int value = 0;
            for (int i = hex.Length - 1; i >= 0; i--)
            {
                value += (int)((Array.IndexOf(hexdict, hex[i].ToString())) * Math.Pow(16.0, (hex.Length - i - 1)));
            }
            return value;
        }

    }
}
