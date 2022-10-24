#!/bin/sh
hoanhao() {
    s=0
    i=1
    while [ $i -lt $1 ]; do
        k=$(($1 % $i))
        if [ $k -eq 0 ]; then
            s=$(($s + $i))
        fi
        i=$(($i + 1))
    done
    if [ $s -eq $1 ]; then
        ktra=1
    else
        ktra=0
    fi
    return "$ktra"
}

read -p "Nhap so: " m
hoanhao $m
if [ $? -eq 1 ]; then
    echo "$m la so hoan hao"
else
    echo "$m khong la so hoan hao"
fi
exit 0
