echo "Enter"
read number

digits=($(echo $number | grep -o .))

sorted=($(printf '%s\n' "${digits[@]}" | sort -n))

echo -n "Largest: "
echo ${sorted[-1]}