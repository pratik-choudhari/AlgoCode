using System;
using System.Collections.Generic;
using System.Linq;

namespace CountSingleDigits
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(CountSingleDigit(99995844)); // Return 2 (only 5 and 8 appear once)
        }
        static int CountSingleDigit(long input)
        {
            var digitString = input.ToString(); // change to string input value.
            var result = 0;
            var distinctDigits = digitString.Distinct(); // find different digits list
            foreach (var distinctDigit in distinctDigits)
            {
                if (digitString.Count(m => m == distinctDigit) == 1) // check different digits count
                {
                    result++;
                }
            }
            return result;
        }
    }
}
