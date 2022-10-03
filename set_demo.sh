#!/bin/sh
filename="vd1.sh"
set `ls -il $filename`
inode="$1"
size="$6"
echo "name\t\tinode\t\tSize"
echo
echo "$filename\t\t$inode\t\t$size"
exit 0
