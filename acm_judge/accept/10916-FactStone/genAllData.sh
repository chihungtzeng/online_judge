OUT=shit.txt
for d in `seq 1960 2160`; do
	echo $d >> $OUT
done
echo "0" >> $OUT
