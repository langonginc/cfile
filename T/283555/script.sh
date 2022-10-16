#!/bin/bash

for ((i=1;i<=10;i++))
do
echo $i
./283555 < $i.in > $i.out
done
