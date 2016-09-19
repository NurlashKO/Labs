name=$1
mpicc $name.c -o $name.out
mpirun -n 4 $name.out
