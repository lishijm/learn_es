#! /bin/bash

read file
if [ -f $file ]
then
	cat $file
elif [ -d file ]
then
	ls $file
else
	echo nothing
fi
