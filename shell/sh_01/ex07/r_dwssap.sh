cat /etc/passwd | awk '!/^#/' | awk 'NR % 2 == 0'| rev | sort -nr | sed -n -e "${FT_LINE1},${FT_LINE2}p" | tr ':' ' ' | awk '{printf "%s", $NF", " }' | awk '{printf substr($0, 1, length($0)-2) "."}'
