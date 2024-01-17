echo -n "enter n: "
read n

r=$n

for (( i=1; i <= n; i++, r-- ))
do
	for (( j=1; j <= i; j++ ))
	do
		echo -n "* "
	done
	echo ""
done
