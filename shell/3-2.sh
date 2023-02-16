#! /bin/bash

read n1 n2
echo "$n1*$n2="`expr $n1 \* $n2` &>>result.txt