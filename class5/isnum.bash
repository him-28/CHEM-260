#!/bin/bash
intregex='^[0-9]+$'
if ! [[ $1 =~ $intregex ]] ; then
echo "$1 is not an integer"
else
echo "$1 is an integer"
fi
