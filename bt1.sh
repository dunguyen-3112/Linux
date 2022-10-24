#!/bin/sh
while [ $# -eq 2 ]; do
	username=$1
	password=$2
	echo "$1 and $2"
	ENTRY=`zenity --username --password`
	u=`echo $ENTRY | cut -d'|' -f1`
	p=`echo $ENTRY | cut -d'|' -f2`
	if [ $u = $username ] && [ $p = $password ]
	then
		echo "Login Success"
		zenity --list \
		--width="800" \
		--height="600" \
  		--title="Choose the Bugs You Wish to View" \
  		--column="Bug Number" --column="Severity" --column="Description" \
    	992383 Normal "GtkTreeView crashes on multiple selections" \
    	293823 High "GNOME Dictionary does not handle proxy" \
    	393823 Critical "Menu editing does not work in GNOME 2.0"
	else
		echo "Login Faill"
	fi
	break
done
exit 0
