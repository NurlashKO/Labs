name=$1
mpic++ $name.cpp -o $name.out
mpirun -np 2 $name.out 2
