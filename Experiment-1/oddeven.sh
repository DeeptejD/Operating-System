echo "enter: "
read a
c=$(($a%2))
if [ $c -eq 0 ]
then
    echo "even"
else
    echo "odd"
fi