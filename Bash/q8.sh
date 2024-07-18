ps aux|awk '{print $1}'|sort|uniq -c|sort -nr|while read count user;do
	echo "User:$user - Processes running: $count"
done
