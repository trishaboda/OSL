#STAR PATTERN for loop
echo "Enter the number of rows for FOR loop: "
read n
for ((i=0; i<n; i++))
do
	for ((j=0; j<i+1; j++))
	do
		echo -n "*"
	done
	echo
done


for ((i=n-1; i>=0; i--))
do
	for ((j=i; j>0; j--))
	do
		echo -n "*"
	done
	echo
done

#STAR PATTERN while loop
echo "Enter the number of rows for WHILE loop:"
read n
i=1
while [ $i -le $n ]
do
    j=1
    while [ $j -le $i ]
    do
        echo -n "*"
        j=$((j + 1))
    done
    echo
    i=$((i + 1))
done

i=$((n - 1))
while [ $i -ge 1 ]
do
    j=1
    while [ $j -le $i ]
    do
        echo -n "*"
        j=$((j + 1))
    done
    echo
    i=$((i - 1))
done