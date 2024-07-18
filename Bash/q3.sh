echo "Enter file name"
read file

echo "Display file which are not start with a or b or c with line numbers\n"
grep -n "^[^a.b.c]" $file
