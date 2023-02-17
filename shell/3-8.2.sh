#! /bin/sh

add(){
	addv=`expr $num1 + $num2`
	echo $addv
}
sub(){
	addv=`expr $num1 - $num2`
	echo $addv
}
mul(){
	addv=`expr $num1 \* $num2`
	echo $addv
}
div(){
	addv=`expr $num1 / $num2`
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
		    sub $num1 $num2
		    ;;
	    \*)
		    mul $num1 $num2
		    ;;
	    /)
		    div $num1 $num2
		    ;;
    esac
done