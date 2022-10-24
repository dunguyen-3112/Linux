#!/bin/sh
read -p "Nhap a= " a
read -p "Nhap b= " b
read -p "Nhap c= " c
delta=$(expr $b \* $b - 4 \* $a \* $c)
if [ $delta -gt 0 ]; then
	x1=1
elif [ $delta -eq 0 ]; then
	echo 0
else
	echo -1
fi
echo "$delta"
exit 0
