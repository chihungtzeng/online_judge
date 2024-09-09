OUT=all.txt
for n in `seq 1 9999`; do
	for m in `seq 1 9999`; do
		echo $m $n >> $OUT
	done
done
echo 0 0 >> $OUT
