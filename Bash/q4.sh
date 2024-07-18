echo "Enter filename"
read file

#if [ ! -s "$file" ]; then
#	echo "file not found"
#	exit 1
#fi

#grep -o '[^ ]*' $file|tr '\n' '#' | awk '{print $0}' ORS=' '|sed 's/#/ /g'
sed 's/ /#/g' $file
echo
