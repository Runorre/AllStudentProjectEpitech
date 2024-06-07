#!/bin/sh
if [ -z "$1" ]
then
    var=$(wc -l)
else
    var=$(cut -d";" -f 3|grep -i "$1"| wc -l)
fi
echo $var
