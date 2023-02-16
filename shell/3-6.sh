#! /bin/bash

read file
if [ -f $file ]
then
	chmod u+x $file
    echo normal >> $file
elif [ -d $file ]
then
	cd $file
    touch dir
    chmod u+x dir
    echo dir
fi