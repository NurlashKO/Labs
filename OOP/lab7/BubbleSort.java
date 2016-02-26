public class BubbleSort implements Sort
{
    static private BubbleSort single = null;

    public void sort(int a[])
    {
        int n = a.length;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                if (a[j] > a[j + 1])
                {
                    int x = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = x;
                }
    }

    private BubbleSort()
    {
    }

    static public BubbleSort getSingle()
    {
        if (single == null)
            single = new BubbleSort();
        return single;
    }
}
