#!/bin/bash
if [ ! -f $1 ]
then
echo "Trouble, could not find input file $1"
exit 1
fi
rm $1
