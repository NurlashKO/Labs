using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    struct ReplaceSuggestionString
    {
        public string replaceString;
        public int position;
        public int length;

        public ReplaceSuggestionString(string replaceString, int position, int length)
        {
            this.replaceString = replaceString;
            this.position = position;
            this.length = length;

        }

        public override string ToString()
        {
            return replaceString;
        }
    }
}
