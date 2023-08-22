read -p 'enter the coefficient of x^2: ' a
read -p 'enter the coefficient of x: ' b
read -p 'enter the constant: ' c

echo "The polynomial is: $a x^2 + $b x + $c = 0"
b=$((-1*$b))

# calculating the discriminant
disc=$(($b*$b))
disc=$(($disc-$((4*$a*$c))))
# echo $disc

if [ $disc -lt 0 ]
then
	echo "no real roots exist"
	exit
fi

decimal_places=4
disc=$(echo "scale=$decimal_places; sqrt($disc)" | bc -l)
# echo $disc
rounded=$(printf "%.0f" $disc)

if [ $rounded -eq 0 ]
then
	root1=$(echo "($b)/(2*$a)" | bc)
	echo "Square roots are: $root1 and $root1"
elif [ $rounded -gt 0 ]
then
	root1=$(echo "($b+$rounded)/(2*$a)" | bc)
	root2=$(echo "($b-$rounded)/(2*$a)" | bc)
	echo "Square roots are: $root1 and $root2"
else
	echo "no real roots exist"
fi

