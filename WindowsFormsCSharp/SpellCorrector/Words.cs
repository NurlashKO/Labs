using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    class Words
    {
        private String[] words;
        private StringDistance calcDist;

        public Words(StringDistance calcDist) {
            this.calcDist = calcDist;
            words = System.IO.File.ReadAllLines("words.txt");
        }

        private Words() { }

        public void setDistanceAlgorithm(StringDistance calcDist) {
            this.calcDist = calcDist;
        }

        public bool contains(string s) {
            return words.Contains(s);
        }

        public List<String> getSimilar(string s, int cnt) {
            SortedSet <Tuple<int, string>> resultWords = new SortedSet<Tuple<int, string>>();
            foreach (string word in words) {
                int d = calcDist.calcSimilarity(s, word);
                resultWords.Add(new Tuple<int, String>(d, word));
                if (resultWords.Count > cnt) resultWords.Remove(resultWords.Last());
            }
            return resultWords.Select(x => x.Item2).ToList();
        }
    }
}
