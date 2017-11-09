#!/bin/bash

variable="data:"

ls -a --file-type | grep -v '[/@]' |while read i
do
var3=$(head -n 1 "$i" | cut -c1-5 )

if [ "$var3" = "$variable" ]
then
echo "$i:" | tr "[:upper:]" "[:lower:]";

for line in `cat "$i" | cut -d'#' -f 1;`; do

if ! [ -z "${line}" ]
then
echo "$line";
fi
done

fi

done