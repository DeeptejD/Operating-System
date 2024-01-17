# echo "Leap years from 2000 to 2025:"
# for year in {2000..2025}; do
#     if (( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )); then
#         echo $year
#     fi
# done

echo "Leap years from 2000 to 2025"
for year in {2000..2025}; do
    if (( $year%4==0 && $year%100!=0 || $year%400==0 )); then
        echo $year 
    fi    
done 