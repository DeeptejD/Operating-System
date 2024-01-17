n=1
while [ $n -eq 1 ]
do
    echo "Enter 2 numbers"
    read a
    read b
    echo "Enter a choice\n1.Add\n2.Sub\n3.Mul\n4.Div\n"
    read choice
    case $choice in
    1) sum=$(($a + $b))
    echo "SUM: $sum"
    ;;
    2) diff=$(($a - $b))
    echo "DIFF: $diff"
    ;;
    3) mul=$(($a * $b))
    echo "MUL: $mul"
    ;;
    4) div=$(($a / $b))
    echo "DIV: $div"
    ;;
    *) echo "Invalid operation\n"
    esac
    echo "Continue? 1 for yes anything else for no"
done 