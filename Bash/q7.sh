display_record(){
	file="$1"
	rec_nu=1

	while IFS=':' read -r firstname middlename lastname address city pin phone;do
	echo "Record $rec_nu"
	echo "$lastname $middlename $firstname"
#	echo "Address:"
	echo "$address"
	echo "$city - $pin"
#	echo "Phone:"
	echo "$phone"
	((rec_nu++))
	echo
  done < "$file"
}
echo "Enter the filename"
read file
display_record "$file"
