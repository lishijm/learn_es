#! /bin/sh

add(){
	addv=`expr $num1 + $num2`
	echo $addv
}


while true
do
    read num1 a num2
    case $a in
	    +)
		    add $num1 $num2
		    ;;
	    -)
		    echo `expr $num1 - $num2`
		    ;;
	    \*)
		    echo `expr $num1 \* $num2`
		    ;;
	    /)
		    echo `expr $num1 / $num2`
		    ;;
    esac
done