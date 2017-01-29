using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    class Formatter
    {
        private static char[] delimiters = new char[] { '\r', '\n', ' ', '.', ',', ';', '?' };

        public static bool isDelimiter(char ch) {
            return delimiters.Contains(ch);
        }

        public static string replaceWord(string text, string word, int pos, int len) {
            if (pos <= text.Length)
                text = text.Remove(pos, len);
            if (pos <= text.Length)
                text = text.Insert(pos, word);
            return text;
        }
    }
}
