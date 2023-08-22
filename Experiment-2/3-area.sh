echo "area of a rectangle, square, circle"

echo "enter length: "
read length
echo "enter breadth: "
read breadth

echo "area of the rectangle is: $(($length*$breadth))"

echo "area of a square"
echo "enter side: "
read breadth

echo "area of the square is: $(($breadth*$breadth))"

echo "area of a triangle"
echo "enter base: "
read base
echo "enter height: "
read height

echo "area of a triangle is: $(($(($base*$height))/2))"

read -p "Enter the radius of the circle: " rad
rad=$(($rad*$rad))
rad=$(($rad*22))
rad=$(($rad/7))
echo "The area of the circle is: $rad"
