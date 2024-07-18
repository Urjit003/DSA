echo "Enter file name"
read file

echo "Display lines which start with a or b or c\n"
grep "^[a,b,c]" $file
