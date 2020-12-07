cat /etc/passwd | grep -v "^#" | sed -n 'n;p' | cut -d ':' -f 1 | rev | sort -r | sed -n $FT_LINE1,$(echo $FT_LINE2)p | sed 's/$/, /g' | tr -d '\n' | sed 's/, $/./g' | tr -d '\n'
