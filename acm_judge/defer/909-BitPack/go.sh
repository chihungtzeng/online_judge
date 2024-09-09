for f in `seq 1 9`; do
	./a.out < $f.in > $f.out
done
ls -l *.out
echo "---expect result----"
cat expectResult.txt
