#! /bin/sh

read mark
tmp=`expr $mark / 10`
    case $tmp in
	    9)
		    echo A
            break
		    ;;
	    8)
		    echo B
            break
		    ;;
	    7)
		    echo C
            break
		    ;;
	    *)
		    echo D
            break
		    ;;
esac