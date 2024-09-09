start=1999997000
end=2000000000
count=`expr $end - $start + 1`
echo $count
for sn in `seq $start $end`; do
    echo "$end $sn"
done
