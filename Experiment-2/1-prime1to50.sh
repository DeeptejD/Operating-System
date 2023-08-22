echo 'printing prime numbers from 1 to 50'
sum=0
for(( i = 1; i <= 50; i++ ))
do
	for(( j = 2; j < $i; j++ ))
	do
		if [ $(($i%$j)) -eq 0 ]
		then		
			break
		fi
	done
	if [ $j -eq $i ]
	then
		echo -n "$i "
		sum=$(($sum+$i))
	fi
done

echo "";
echo "The Sum: $sum"
