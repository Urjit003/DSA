if [ "$#" -lt 2 ]; then
	echo "plz provide 1 or more arguments"
	exit 1
fi
str=$1
shift
for file in "$@"; do
	if [ -f "$file" ]; then
		echo "File: $file - Number of lines containing '
		$str': $(grep -c "$str" "$file")"
	else
		echo "File not found: $file"
	fi
done
