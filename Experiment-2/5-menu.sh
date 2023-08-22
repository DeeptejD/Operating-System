echo "Menu driven program"
echo "1. Display the present working directory
2. Display users of the system
3. Display calendar
4. Exit
Enter the choice: "

while [ true ]
do

read choice

case $choice in
"1")
	pwd # present working directory
	;;
"2")
	who # displaying the current users of the system
	;;
"3")
	read -p 'Enter the year: ' year
	read -p 'Enter the month (number, 1 to 12): ' month
	cal $month $year
	;;
"4")
	exit
	;;
*)
	echo "Invalid"
	;;
esac	
done
