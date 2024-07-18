echo "Enter filename"
read file

vowel_counter=$(grep -o -i '[aeiou]' "$file"|wc -l)
echo "Total vowels: $vowel_counter"
