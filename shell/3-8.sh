#! /bin/sh

while true
do
    read num1 a num2
    case $a in
	    +)
		    echo `expr $num1 + $num2`
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