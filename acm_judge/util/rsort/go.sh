gcc -o gendata gen_data.c
gcc -o rsort rsort.c -lrt
gcc -o qsort qsort.c -lrt
echo "----gen data-----"
./gendata 
echo
echo "----rsort-----"
/usr/bin/time ./rsort
echo
echo "----qsort-----"
/usr/bin/time ./qsort

