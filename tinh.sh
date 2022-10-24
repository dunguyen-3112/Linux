#!/bin/sh
tinh() {
    thuong=$(echo "scale=5; $1/$2" | bc)
    echo $thuong
}
read -p "Nhap so a= " a
read -p "Nhap so b= " b

y=$(tinh $a $b)

awk -vA="$y" 'BEGIN {printf "Ket qua = %.2f\n",A}'
exit 0
