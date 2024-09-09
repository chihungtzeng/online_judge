gcc 11926-4.c -o current
./accept < in6.txt > ok.txt
./current < in6.txt > t
diff ok.txt t

