#!/bin/sh
fx() {
	i=1;
	while [ "$i" -lt 3 ];do	
		i=`expr $i + 1`
		echo "Hello Word!";
	
	done
	echo "Hello word!";
}
fx
exit 0
