#!/bin/bash
if [ -d $1 ]; then
echo "Directory named $1 already exists"
exit 1
elif [ -f $1 ]; then
echo "File named $1 already exists"
exit 1
else
mkdir $1
echo "Okay I made a directory named $1"
fi
