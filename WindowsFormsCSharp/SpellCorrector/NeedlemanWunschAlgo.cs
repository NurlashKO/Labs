using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    class NeedlemanWunschAlgo: StringDistance
    {
                private const int maxLen = 50;
        private int[,] dist = new int[maxLen, maxLen];
        private int[,] keyDistance = new int[300, 300];
        private int D;

        public NeedlemanWunschAlgo()
        {
            int[,] buf = new int[,] {
	            {10,	-1,	-3,	-4},
	            {-1,	7,	-5,	-3},
	            {-3,	-5,	9,	0},
	            {-4,	-3,	0,	8}
            };
            string s = "ACGT";
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    keyDistance[s[i], s[j]] = buf[i, j];
        }

        public int calcSimilarity(string s, string t)
        {
            int n = s.Length, m = t.Length;
            if (n == 0 || m == 0) return Math.Max(n, m);
            for (int i = 0; i <= Math.Max(n, m); i++)
                dist[i, 0] = dist[0, i] = i * D;
            for (int i = 1; i <= s.Length; i++)
                for (int j = 1; j <= t.Length; j++)
                {
                    dist[i, j] = Math.Min(dist[i - 1, j] + D, dist[i, j - 1] + D);
                    dist[i, j] = Math.Min(dist[i, j], dist[i - 1, j - 1] + (keyDistance[s[i - 1], t[j - 1]]));
                }
            return dist[n, m];
        }
    }
}
