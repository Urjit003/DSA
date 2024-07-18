search(){
	flag=false
	option=$1
	read -p "Enter data to search" target
	while read -r bill_no cust_no cust_name others ;
	do
		if [ $option -eq 1 ];
		then
			search=$cust_no
		elif [ $option -eq 2 ];
		then
			search=$bill_no
		elif [ $option -eq 3 ];
		then
			search=$cust_name
		fi
		if [ $search == $target ];
		then	
			echo $bill_no $cust_no $cust_name $others
			flag=true
			break;
		fi
	done<cust13.txt
}
echo "\nHow ypu want to search \n1 for cust_no \n2 for bill_no \n3 for cust_name"
read -p "Enter choice: " choice
if [ $choice -gt 3 ] || [ $choice -lt 1 ];
then
	echo "Invalid opt"
else
	search $choice
fi
