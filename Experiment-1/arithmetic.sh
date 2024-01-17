n=1
while [ $n -eq 1 ]
do
	echo "Enter two numbers"
	read a
	read b
	echo "Menu\n"
	echo "1. Add\n2. Substracrt\n3. Multiply\n4. Divide\n"
	echo "Enter your choice"
	read choice
	
	case $choice in
	1) s=$(($a + $b))
	   echo "SUM = $s";;
	2) d=$(($a - $b))
	   echo "DIFFERENCE = $d";;
	3) p=$(($a * $b))
	   echo "Product = $p";;
	4) m=$(($a / $b))
	   echo "Divide = $m";;
	esac
	echo "Do you want to continue? Press 1 to continue else 2"
	read n
done

