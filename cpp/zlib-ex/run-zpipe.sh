set -e
set -x
g++ -lz -lglog zpipe.c 
./a.out

md5sum lett.bin temp.bin lett.bin.zpipe 
