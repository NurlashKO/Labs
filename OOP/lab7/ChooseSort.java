public class ChooseSort implements Sort
{
    private static ChooseSort single = null;

    public void sort(int[] a)
    {
        int n = a.length;
        for (int i = 0; i < n; i++)
        {
            int mi = i;
            for (int j = i; j < n; j++)
                if (a[j] < a[mi])
                    mi = j;
            int x = a[i];
            a[i] = a[mi];
            a[mi] = x;
        }
    }

    private ChooseSort()
    {
    }

    static public ChooseSort getSingle()
    {
        if (single == null)
            single = new ChooseSort();
        return single;
    }
}
