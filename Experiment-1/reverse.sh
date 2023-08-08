echo "enter: "
read n
rev=0
a=0

while [ $n != 0 ]
do
a=$(( $n % 10 ))
rev=$((($rev*10)+$a ))
n=$(( $n / 10 ))
done

echo "reversed number: $rev"