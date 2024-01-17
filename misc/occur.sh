echo "enter size of string"
read n
echo "enter string"
read s
echo "enter target character"
read c

cnt=0
for(( i = 0; i < ${#s}; i++ ))
do
	if [ ${s:i:1} = $c ]
	then
		cnt=$(($cnt+1))
	fi
done

echo "the count of $c is $cnt "
