#! /bin/bash

read file1 file2
sta(){
    echo `wc $file1`
    echo `wc $file2`
}
#cat(){
#}
connect(){
    cat $file1 >>$file2
}
cp(){
    cat $file1 >$file2
}

if [ -f $file1 ] && [ -f $file2 ]
then
    while true
    do
        read sel
        case $sel in
            "sta")sta $file1 $file2
                ;;
            "cat")cat $file1
                cat $file2
                ;;
            "connect")connect $file1 $file2
                ;;
            "cp")cp $file1 $file2
                ;;
            *) break
            ;;
        esac 
    done
else
    echo err
fi