echo "sum and avg of n numbers"
echo "Enter the number of numbers: "
read n
i=0
sum=0

while [ $i -ne $n ]
do
read x
sum=$(($sum+$x))
i=$(($i+1))
done

echo "sum: $sum"
echo "avg: $(($sum/$n))"
