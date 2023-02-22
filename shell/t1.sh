#! /bin/bash

read a b
seq $a $b
echo $a
echo a
echo "$a"
echo `expr $a \* $a`
echo 'a'
if [ $a -gt $b ]
then
    echo $a >record.txt
else
    echo $b >record.txt
fi

if [ $a -eq $b ]
then
    echo '==' >>record.txt
else
    echo '!=' >>record.txt
fi
read sel
case $sel in
    1)
        echo $a
        ;;
    2)
        echo `expr $b / $a`
        ;;
    *)
        echo $sel
        ;;
esac

for i in `seq $a $b`
do
    for j in `seq $a $i`
    do
        echo -n -e "$j * $i = `expr $i \* $j `\t" >>record.txt
    done
    echo -e "\n" >>record.txt
done

cat record.txt