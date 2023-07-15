#! /bin/bash

read year month
t1=`expr $year % 4`
t2=`expr $year % 100`
t3=`expr $year % 400`
if [ $t1 -eq 0 ] && [ $t2 -ne 0 ]
then
    case $month in
        1)
        echo 31
            ;;
        3)
        echo 31
            ;;
        5)
        echo 31
            ;;
        7)
        echo 31
            ;;
        8)
        echo 31
            ;;
        10)
        echo 31
            ;;
        12)
            echo 31
            ;;
        4)
        echo 30
            ;;
        6)
        echo 30
            ;;
        9)
        echo 30
            ;;
        11)
            echo 30
            ;;
        2)
            echo 29
            ;;
    esac
elif [ $t3 -eq 0 ]
then
    case $month in
        2)
            echo 29
            ;;
        1)
            echo 31
            ;;
        3)
            echo 31
            ;;
        5)
            echo 31
            ;;
        7)
            echo 31
            ;;
        8)
            echo 31
            ;;
        10)
            echo 31
            ;;
        12)
            echo 31
            ;;
        4)
            echo 30
            ;;
        6)
            echo 30
            ;;
        9)
            echo 30
            ;;
        11)
            echo 30
            ;;
    esac
else
    case $month in
        1)
        echo 31
        ;;
        3)
        echo 31
        ;;
        5)
        echo 31
        ;;
        7)
        echo 31
        ;;
        8)
        echo 31
        ;;
        10)
        echo 31
        ;;
        12)
            echo 31
        ;;
        4)
        echo 30
        ;;
        6)
        echo 30
        ;;
        9)
        echo 30
        ;;
        11)
        echo 30
        ;;
        2)
        echo 28
        ;;
    esac
fi