#!/bin/bash
./isprime <<< $1
if [ $? -eq 1 ]; then
 echo "Not prime"
else
 echo "Prime"
fi 
