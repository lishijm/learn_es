#! /bin/bash

read file1 file2
if [ -f $file1 ]
then
    if [ -f $file2 ]
    then 
        if [ $file1 -nt $file2 ]
        then
            cp $file1  $file2
        else
            cp $file2  $file1
        fi
    fi
fi
if [ -d $file1 ]
then
    if [ -f $file2 ]
    then
        mv $file2 $file1
    fi
elif [ -d $file2 ]
then
    if [ -f $file1 ]
    then
        mv $file1 $file2
    fi
fi