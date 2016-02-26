#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SWAP(x,y) do {    \ 
    typeof(x) _x = x;      \
    typeof(y) _y = y;      \
    x = _y;                \
    y = _x;                \
} while(0)

struct task
{
    int arrival, len, pr, id; 
};

struct process
{
    int b, e, id;
} result[1000000];

typedef struct{
    int arrival, len, pr, id;
} ttask;

typedef struct {
    int b, e, id;
} tprocess;


ttask t[1000000], working[1000000];
int cnt;



int cmpArrival(const void *a, const void *b)
{
    ttask *A = (ttask *)a, *B = (ttask *)b;
    if (A -> arrival < B -> arrival) return -1;
    if (A -> arrival == B -> arrival) return 0;
    return 1;
}

int cmpLen(const void *a, const void *b)
{
    ttask *A = (ttask *)a, *B = (ttask *)b;
    if (A -> len < B -> len) return -1;
    if (A -> len  == B -> len) return 0;
    return 1;
}

int cmpPriority(const void *a, const void *b)
{
    ttask *A = (ttask *)a, *B = (ttask *)b;
    if (A -> pr < B -> pr) return -1;
    if (A -> pr  == B -> pr) return 0;
    return 1;
}

void add(int b, int e, int id)
{
    result[cnt].b = b;
    result[cnt].e = e;
    result[cnt].id = id;
    cnt++;
}

void toResult(ttask *t, int n)
{
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        add(last, last + t[i].len, t[i].id);
        last += t[i].len;
    }
}

void showData()
{
    FILE *o = fopen("out", "w");
    fprintf(o, "+");for(int i = 0; i < 100; i++)fprintf(o, "-");fprintf(o, "+\n");
    fprintf(o, "|");
    
    int c = 1, x = result[cnt - 1].e, p = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (result[i].id == result[c - 1].id)
            result[c - 1].e = result[i].e;
        else
            result[c++] = result[i];
    }
    cnt = c;

    for (int i = 0; i < cnt; i++)
    {
        result[i].b = round(result[i].b / (x + 0.0) * 100);
        result[i].e = round(result[i].e / (x + 0.0) * 100);
    }
    for (int i = 0; i < 100; i++)
    {
        if (result[p].b <= i && i <= result[p].e) fprintf(o, "%d", result[p].id);
        if (i < result[p].b) fprintf(o, "#");
        if (i > result[p].e)
        {
            fprintf(o, "|");
            p++;
        }

    }

    fprintf(o, "|\n");
    fprintf(o, "+");for(int i = 0; i < 100; i++)fprintf(o, "-");fprintf(o, "+\n");
    fclose(o);
}

void firstStart(ttask *t, int n)
{
    qsort(t, n, sizeof(*t), cmpArrival);
    toResult(t, n);
}

void shortFirst(ttask *t, int n)
{
    qsort(t, n, sizeof(*t), cmpLen);
    toResult(t, n);
}

void priorityFirst(ttask *t, int n)
{
    qsort(t, n, sizeof(*t), cmpPriority);
    toResult(t, n);
}

void shortRemaning(ttask *t, int n)
{
    qsort(t, n, sizeof(*t), cmpArrival);
    int r = 0, last = t[0].arrival;

    while (n)
    {
        int p = 0, nx = (int)1e9;
        for (int i = 0; i < n; i++)
            if (t[i].arrival < last) t[i].arrival = last;
        for (int i = 0; i < n; i++)
        {
            if (t[i].arrival == last)
                if (t[i].len < t[p].len) p = i;
            if (t[i].arrival > last && t[i].arrival < nx) nx = t[i].arrival;
        }
        int step = 0;
        if (t[p].len >= nx - t[p].arrival) 
            step = nx - t[p].arrival;
        else
            step = t[p].len;
        
        add(last, last + step, t[p].id);
        t[p].len -= step;
        if (t[p].len == 0)
        {
            SWAP(t[p], t[n - 1]);
            n--;
        }
        last = last + step;
    }
    showData();
}

void roundRobin(ttask *t, int n)
{
    qsort(t, n, sizeof(*t), cmpLen);
    printf("quantum : ");
    int q = 0, step = 0, last = 0;
    scanf("%d", &q);
    
    while (1)
    {
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (t[i].len > 0)
            {
                int step = q;
                if (t[i].len <= q) step = t[i].len;
                t[i].len -= step;
                add(last, last + step, t[i].id);
                last += step;
                f = 1;
            }
        }
        if (!f) break;
    }
}

int main()
{
    int n = 0;
    
    FILE *f = fopen("tasks", "r");

    while (fscanf(f, "%d %d %d", &t[n].arrival, &t[n].len, &t[n].pr) > 0)
    {
        t[n].id = n + 1;    
        n++;
    }
    fclose(f);

    int funcType;
    printf("FCFS - 0\nshortest Time - 1\npriority - 2\n");
    printf("remaining Time - 3\nround Robin - 4\n");
    scanf("%d", &funcType);
    
    switch (funcType) 
    {
        case 0: 
            firstStart(t, n);
            break;
        case 1:
            shortFirst(t, n);
            break;
        case 2:
            priorityFirst(t, n);
            break;
        case 3:
            shortRemaning(t, n);
            break;
        case 4:
            roundRobin(t, n);
            break;
        default :
            printf("Wrong input");
            return 0;
    }
    showData();
    return 0;
}

