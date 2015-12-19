#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Command requires 2 arguments."
    exit 1
fi
b=10
while [ $b -le $2 ]
do
   Ising_model.py $2 $1 | head -1
   let b+=5   
done
 
