echo "enter: "
read n
check=$n
rev=0
a=0

while [ $n != 0 ]
do
a=$(( $n % 10 ))
rev=$((($rev*10)+$a ))
n=$(( $n / 10 ))
done

if [ $rev -eq $check ]
then
echo "Pallindrome"
else
echo "not a pallindrome"
fi
