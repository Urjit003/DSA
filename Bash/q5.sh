echo "Enter file name"
read file

#grep "^[Tt][hs]" $file
sed -n '/^[Tt][hs]/p' "$file"
