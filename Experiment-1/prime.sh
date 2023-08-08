echo "prime numbers"
read n
i=2

while [ $i -ne $n ]
do
if [ $(($n%$i)) -eq 0 ]
then
echo "not prime"
exit
else
i=$(($i+1))
fi

echo "prime"
done

