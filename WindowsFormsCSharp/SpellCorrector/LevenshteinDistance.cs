using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    class LevenshteinDistance : StringDistance
    {
        private const int maxLen = 50;
        private int[,] dist = new int[maxLen, maxLen];
        public int calcSimilarity(string s, string t)
        {
            int n = s.Length, m = t.Length;
            if (n == 0 || m == 0) return Math.Max(n, m);
            for (int i = 0; i <= Math.Max(n, m); i++) 
                dist[i, 0] = dist[0, i] = i;
            for (int i = 1; i <= s.Length; i++)
                for (int j = 1; j <= t.Length; j++)
                {
                    dist[i, j] = Math.Min(dist[i - 1, j] + 1, dist[i, j - 1] + 1);
                    dist[i, j] = Math.Min(dist[i, j], dist[i - 1, j - 1] + (s[i - 1] == t[j - 1] ? 0 : 2));
                }
            return dist[n, m];
        }
    }
}
