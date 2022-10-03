#!/bin/sh
if test $# -eq 0
	then
		echo "Usage: $0 ordinary_file"
		echo "No params"
		exit 1
fi
if test $# -gt 1
	then
		echo "Usage: $0 ordinary_file"
		exit 1
fi
if test -f "$1"
	then
		filename="$1"
		set `ls -il $filename`
		inode="$1"
		size="$6"
		echo "Name\tInode\tSize"
		echo
		echo "$filename\t$inode\t$size"
		exit 0
		
fi
if test -d "$1"
	then
		echo "Usage: $0 ordinary_dir"
		exit 1
fi
	
echo "$0: argment must be an ordinary file"
exit 1
