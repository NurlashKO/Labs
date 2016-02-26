public class Main
{
    public static void main(String[] args)
    {
        int[] a = {1, 5, 3 ,6};

        Sorting func1 = new Sorting(BubbleSort.getSingle());
        func1.displaySorted(a);
        int[] b = {7, 10, 20, 1, 5};
        Sorting func2 = new Sorting(BubbleSort.getSingle());
        func2.displaySorted(b);
    }
}

