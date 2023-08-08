echo "factorial of a number"
echo "enter: "
read a
i=$a
fact=1
while [ $i -ne 0 ]
do
    fact=$(($fact*$i))
    i=$(($i-1))
done

echo "factorial: $fact"
