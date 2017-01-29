using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    class LevenshteinDistanceKeySimilarity: StringDistance
    {
        private const int maxLen = 50;
        private int[,] dist = new int[maxLen, maxLen];
        private int[,] keyDistance = new int[300, 300];

        public LevenshteinDistanceKeySimilarity() { 
            string[] s = new string[] {
                "1234567890",
                "qwertyuiop",
                "asdfghjkl",
                "zxcvbnm"
            };

            for (int i1 = 0; i1 < 4; i1++) {
                for (int j1 = 0; j1 < s[i1].Length; j1++) {
                    for (int i2 = 0; i2 < 4; i2++) {
                        for (int j2 = 0; j2 < s[i2].Length; j2++) {
                            keyDistance[s[i1][j1], s[i2][j2]] = Math.Abs(i1 - i2) + Math.Abs(j1 - j2);
                        }
                    }
                }
            }
            
        }

        public int calcSimilarity(string s, string t)
        {
            int n = s.Length, m = t.Length;
            if (n == 0 || m == 0) return Math.Max(n, m);
            for (int i = 0; i <= Math.Max(n, m); i++)
                dist[i, 0] = dist[0, i] = i;
            for (int i = 1; i <= s.Length; i++)
                for (int j = 1; j <= t.Length; j++)
                {
                    dist[i, j] = Math.Min(dist[i - 1, j] + 2, dist[i, j - 1] + 2);
                    dist[i, j] = Math.Min(dist[i, j], dist[i - 1, j - 1] + (keyDistance[s[i - 1], t[j - 1]]));
                }
            return dist[n, m];
        }
    }
}
