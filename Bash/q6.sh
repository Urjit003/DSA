echo "Enter file name"
read file

#grep "^[ ]" $file
sed -n '/^[ ]/p' "$file"
