public class Sorting {
    private Sort sorting;

    public void setSort(Sort newSorting)
    {
        sorting = newSorting;
    }

    public Sorting(Sort newSorting)
    {
        setSort(newSorting);
    }

    public void displaySorted(int[] a)
    {
        sorting.sort(a);
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println();
    }
}

