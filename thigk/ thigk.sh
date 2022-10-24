#!/bin/sh
echo "  *****************************************************************************\n
        * Bai thi giua ky mon: Lap trình Linux. *\n
        * Ho va ten: Nguyen Huu Du *\n
        * Nhom: 20.Nh11 *\n
        * Masv: 102190157 *\n
        * De so: 01. *\n
        *****************************************************************************\n
        "
while [ True ]; do

    read -p "
        Vui long chon mot trong cac tuy chon sau; nhap ky tu va nhan phim <Enter>.\n
        a hoac A Hien thi thu muc hien hanh.\n
        b hoac B Liet ke cac file trong thu muc nhap vao.\n
        c hoac C Hien thi ngay gio hien hanh.\n
        d hoac D Hien thi thong bao file vua nhap la mot ordinary file hay directory.\n
        e hoac E Thuc thi mot lenh nhap vao\n
        q hoac Q Thoat khoi shell.\n
        *****************************************************************************\n
        Nhap tuy chon va nhan phim <Enter>: " chon
    case "$chon" in
    "a" | "A") echo $(pwd) ;;
    "b" | "B") {
        read -p "Vui nhap duong dan thu muc de hien thi file: " folder

        echo $(ls -il $folder)
    } ;;
    "C" | "c") echo $(date) ;;
    "d" | "D") {
        if [ -d "$0"]; then
            $(zenity --info --text="$0 is ordinary file!")
        else
            $(zenity --info --text="$0 is directory!")
        fi
    } ;;
    "e" | "E") {
        read -p "Vui long nhap lenh: " lenh
        echo $($lenh)
    } ;;
    "q" | "Q") break ;;
    *) continue ;;
    esac
done
exit 0
