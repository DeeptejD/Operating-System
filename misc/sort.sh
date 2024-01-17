echo "enter number of elements"
read n

declare -a array

echo "enter the $n numbers"
for(( i = 0; i < n; i++ ))
do
	read array[$i]
done

for(( i = 0; i < n-1; i++ ))
do
	for(( j = 0; j < n-i-1; j++ ))
	do
		if [ ${array[$j]} -gt ${array[($j+1)]} ]
		then
			temp=${array[$j]}
			array[$j]=${array[($j+1)]}
			array[($j+1)]=$temp
		fi
	done
done

for(( i = 0; i < n; i++ ))
do
	echo -n "${array[$i]} "
done

