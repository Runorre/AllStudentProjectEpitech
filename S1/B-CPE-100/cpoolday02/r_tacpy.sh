#!/bin/sh
 cut -d":" -f1 | sed -n "2~2p" | rev | sort -r | sed -ne ""$MY_LINE1"~"$MY_LINE2"p"| sed '$!s/$/,/'| sed '$s/$/./'  | tr "\n" " " 
echo ""
