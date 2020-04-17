#!/bin/bash

arr=( "$@" )

sumO=0

for i in ${arr[@]}
do
    sumO=$(($sumO+$i)) ;
done

echo $sumO



