echo "Enter a number:"
read number

# Convert the number to an array of digits
# digits=($(echo $number | grep -o .))
digits=($(echo $number | grep -o .))

# Sort the array in ascending order
# sorted_digits=($(printf '%s\n' "${digits[@]}" | sort -n))
sorted_digits=($(printf '%s\n' "${digits[@]}" | sort -n))

# Get the second smallest and second largest digits
second_smallest=${sorted_digits[1]}
second_largest=${sorted_digits[-2]}

# Calculate the difference
difference=$((second_largest - second_smallest))

echo "Second Smallest Digit: $second_smallest"
echo "Second Largest Digit: $second_largest"
echo "Difference: $difference"
