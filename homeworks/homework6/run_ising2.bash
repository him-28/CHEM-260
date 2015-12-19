#!/bin/bash
if [ $# -gt 3 ]; then
    echo "Command requires 3 arguments."
    exit 1
fi
b=10
if [ $# -eq 3 ];then
while [ $b -le $2 ]
do
   Ising_model.py $2 $1 | head -1
   let b+=$3   
done
exit 1 
fi
if [ $# -eq 2 ];then
while [ $b -le $2 ]
do
   Ising_model.py $2 $1 | head -1
   let b+=5
done
exit 1 
fi
