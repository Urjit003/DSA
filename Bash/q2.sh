echo "Enter file name"
read file

echo "Display file which are not start with a or b or c\n"
grep "^[^a,b,c]" $file
