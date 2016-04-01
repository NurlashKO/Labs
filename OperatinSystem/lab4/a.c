#include <stdio.h>

int n, s[11111], x, f, ptr;

void firstFit(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= x)
        {
            printf("Allocated frame number %d.\n size changed from %d to %d\n",
                    i, s[i], s[i] - x);
            s[i] -= x;
            ptr = i;
            return ;
        }
    }
    printf("Can not make allocation\n");
}

void bestFit(int x)
{
    int p = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= x)
            if (p == -1 || s[p] - x > s[i] - x)
                p = i;
    }
    if (p == -1)
        printf("Can not make allocation\n");
    else
    {
        ptr = p;
        printf("Allocated frame number %d.\n size changed from %d to %d\n",
                    p, s[p], s[p] - x);
        s[p] -= x;
    }
}

void nextFit(int x)
{
    for (int i = ptr; i < n; i++)
    {
        if (s[i] >= x)
        {
            printf("Allocated frame number %d.\n size changed from %d to %d\n",
                    i, s[i], s[i] - x);
            s[i] -= x;
            ptr = i;
            return ;
        }
    }

    for (int i = 0; i < ptr; i++)
    {
        if (s[i] >= x)
        {
            printf("Allocated frame number %d.\n size changed from %d to %d\n",
                    i, s[i], s[i] - x);
            s[i] -= x;
            ptr = i;
            return ;
        }
    }
    ptr = 0;
    printf("Can not make allocation\n");
}

void worstFit(int x)
{
    int p = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= x)
            if (p == -1 || s[p] - x < s[i] - x)
                p = i;
    }
    if (p == -1)
        printf("Can not make allocation\n");
    else
    {
        ptr = p;
        printf("Allocated frame number %d.\n size changed from %d to %d\n",
                    p, s[p], s[p] - x);
        s[p] -= x;
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    printf("Enter Memory Frames Count : ");
    scanf("%d", &n);

    printf("Enter Frames Sizes : \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);

    while (1)
    {
        printf("\n");
        printf("Available Memory Frame Sizes\n");
        for (int i = 0; i < n; i++)
            printf("%d\n", s[i]);
        printf("Allocate Memory Size : \n");
        scanf("%d", &x);
        printf("Choose Algorithm : \n");
        printf("1) First-Fit\n");
        printf("2) Best-Fit\n");
        printf("3) Next-Fit\n");
        printf("4) Worst-Fit\n");
        scanf("%d", &f);

        switch (f)
        {
            case 1 :
                firstFit(x);
                break;
            case 2 : 
                bestFit(x);
                break;
            case 3 :
                nextFit(x);
                break;
            case 4 :
                worstFit(x);
                break;
            default :
                printf("Wrong Input\n");
                return 0;
        }
    }

}
