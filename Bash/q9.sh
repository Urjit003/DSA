file="book9.txt"

add(){
	echo "Enter info  for new book:"
	echo "Format must be bno-bname-bauthor-bdateofpurchase"
	read -p "New Record: " new_rec
	echo "$new_rec">>"$file"
	echo "New record add successfully.........."
}

modify(){
	read -p "Enter bno of the record to modify: " bno
	if grep -q "^$bno-" "$file"; then
		echo "Current details:"
		grep "^$bno-" "$file"
		echo "Enter new info for book_no $bno:"
		echo "format......"
		read -p "Updated record: " up_rec
		sed -i "s/^$bno-.*/$up_rec/" "$file"
		echo "Modified succesfully........."
	else
		echo "book with book_no $bno not found..:-)"
	fi
}

delete(){
	read -p "Enter book_no for delete the record: " bno
	if grep -q "^$bno-" "$file";then
		grep -v "^$bno-" "$file">tmp && mv tmp "$file"
		echo "Deleted record successfully........."
	else
		echo "not found"
	fi
}

while true :
do
	echo
	echo "Choose any operation:"
	echo "1.Add"
	echo "2.Modify"
	echo "3.Delete"
	echo "4.exit"

	read -p "Enter your choice: " choice
	case "$choice" in
		1)add;;
		2)modify;;
		3)delete;;
		4)echo "Exiting pro";exit 0;;
		*)echo "Invalid choice plz enter 1,2,3,4";;
	esac
done

