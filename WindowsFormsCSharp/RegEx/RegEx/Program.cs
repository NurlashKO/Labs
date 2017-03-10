using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace ConsoleApplication1
{
    class Program
    {

        static bool isPhone(string str) {
            string pattern = @"^\(?(\d{3})\)?[- ]?(\d{3})-?(\d{4})$";
            Regex regex = new Regex(pattern);
            return regex.IsMatch(str);
        }

        static bool isEmail(string str) {
            string pattern = @"^\w+@\w+\.\w+$";
            Regex regex = new Regex(pattern);
            return regex.IsMatch(str);
        }

        static string matchPhone(string str) {
            string pattern = @"^\(?(\d{3})\)?[- ]?(\d{3})-?(\d{4})$";
            Regex regex = new Regex(pattern);
            if (!regex.IsMatch(str)) return "Error";
            Match phoneMatch = regex.Match(str);
            return String.Format("({0}) {1}-{2}", phoneMatch.Groups[1].Value, 
                                                    phoneMatch.Groups[2].Value, 
                                                    phoneMatch.Groups[3].Value);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Phone regex :");
            string phone1 = "(555)555-1212";
            string phone2 = "(555) 555-1212";
            string phone3 = "555-555-1212";
            string phone4 = "5555551212";
            ///TRUE
            Console.WriteLine(isPhone(phone1));
            Console.WriteLine(isPhone(phone2));
            Console.WriteLine(isPhone(phone3));
            Console.WriteLine(isPhone(phone4));

            string bPhone1 = "((555))555-1212";
            string bPhone2 = "(555)1-555-1212";
            string bPhone3 = "555a555-1212";
            string bPhone4 = "555 555 1212";
            /// FALSE
            Console.WriteLine(isPhone(bPhone1));
            Console.WriteLine(isPhone(bPhone2));
            Console.WriteLine(isPhone(bPhone3));
            Console.WriteLine(isPhone(bPhone4));

            Console.WriteLine("Email regex: ");
            ///TRUE
            Console.WriteLine(isEmail("mymail@gmail.com"));
            Console.WriteLine(isEmail("a@a.com"));

            ///FALSE
            Console.WriteLine(isEmail(".asd@gmail.com"));
            Console.WriteLine(isEmail("zh.nurlan96@.com"));
            Console.WriteLine(isEmail("zh.nurlan96@gmail.com"));
            Console.WriteLine(isEmail("@gmail.com"));
            Console.WriteLine(isEmail("zh.nurlan96gmail.com"));


            Console.WriteLine("Task3, matching numbers :");
            Console.WriteLine(matchPhone(phone1));
            Console.WriteLine(matchPhone(phone2));
            Console.WriteLine(matchPhone(phone3));
            Console.WriteLine(matchPhone(phone4));

            Console.ReadKey();
        }
    }
}
