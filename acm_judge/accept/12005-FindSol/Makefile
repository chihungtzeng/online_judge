CFLAGS = -lm -O2
INPUT = in2.txt

v3: findsol-3.c
	gcc $(CFLAGS) findsol-3.c -o v3
	time ./v3 < in2.txt > in2.out3

gen: genInput.c
	gcc $(CFLAGS) genInput.c -o gen
	./gen > $(INPUT)

java: Main.java
	javac Main.java
	time java Main < $(INPUT) > $(INPUT).outJava

cprog: 
	gcc $(CFLAGS) findsol.c -o v1
	gcc $(CFLAGS) findsol-2.c -o v2
	time ./v1 < $(INPUT) > $(INPUT).out1
	time ./v2 < $(INPUT) > $(INPUT).out2

all: gen java cprog
