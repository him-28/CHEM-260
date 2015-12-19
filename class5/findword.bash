#!/bin/bash
if grep $1 $2 &> /dev/null
then
echo "I found $1 in file $2"
else
echo "I did not find $1 in $2"
fi
