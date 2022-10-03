#!/bin/sh
if [ "$#" -eq 0]
    then
        echo "Usage: $0 file"
        exit 1
elif [ -d "$1"]
    then
        nfiles = `ls "$1" | wc -w`
        echo "The number of files in the directory is $nfiles"
        exit 0
else
    ls "$1" 2>/dev/null | grep "$1" 2>/dev/null 1>2
    if [ $? -ne 0]
        then
            echo "$1: not found"
            exit 1
    fi
    if [ -f "$1"]
        then
            filename="$1"
            set `ls -il $filename`
            shift 4
            inode="$1"
            size="$6"
            echo "Name\tInode\tSize"
            echo
            echo"$filename\t$size\t$inode"
            exit 0
    else    
        echo "$0: argument must be an ordinary file or directory"
        exit 1
    fi
fi
exit 0
        