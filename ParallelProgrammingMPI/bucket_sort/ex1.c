#include <stdio.h>
#include "mpi.h"

int n, a[1000], res[1000], cnt[1000];

void add(int rank) {
    cnt[rank]++;
}

int main( argc, argv )
int  argc;
char **argv;
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int rank, size;
    rank = size = n;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    //MPI_Broadcast(a, n);
    add(rank);
    
    int s = 0;
    for (int i = 0; i <= n; i++) {
        s += cnt[i];
        if (s >= rank) {
            res[rank] = i;
            break;
        }
    }
    MPI_Finalize();

    for (int i = 0; i < n; i++)
        printf("%d", res[i]);
    return 0;
}
