echo -n "enter the number"
read a

org=$a
r=0

while [ $a -ne 0 ]
do
	c=$(($a%10))
	r=$((($r*10)+$c))
	a=$(($a/10))
done

if [ $org -eq $r ]
then
	echo "it is a palindrome"
else
	echo "it is not a palindrome"
fi

