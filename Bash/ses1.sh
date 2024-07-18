echo "Enter 5 digit number"
read num
sum=0
for n in "${num[@]}"; do
	num_str="$n"
	fd="${num_str:0:1}"
	ld="${num_str: -1}"
	sum=$((sum+fd+ld))
done
echo "Sum of first and last digit is:$sum"
