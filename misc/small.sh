echo -n "enter the number"
read a

m=9
while [ $a -ne 0 ]
do
	c=$(($a%10))
	a=$(($a/10))
	if [ $m -gt $c ]
	then
		m=$c
	fi
	
done

echo "smallest digit is $m"
