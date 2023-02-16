#! /bin/bash

read num1 num2
#for i in `seq 1 200`
for i in `seq $num1 $num2`
do
	echo $i
done
