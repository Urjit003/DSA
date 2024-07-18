ls -l|awk 'NR>1 {print $2,$10}'|sort -n
