#!/bin/bash
if [ $# -gt 3 ]; then
 echo "Script takes 3 arguments atmost"
 exit 1
fi
if [ ! -f $1 ]
then
echo "No file found"
exit 1
fi
intregex='^[0-9]+$'
if ! [[ $2 =~ $intregex ]] ; then
 echo "Second argument must be an integer"
 exit 1
fi
if [ $# -eq 2 ]
then
  echo  "Head:"
  head -$2 $1
  echo  "Tail:"
  tail -$2 $1
exit 1
fi

if [ $# -eq 3 ]
then
if ! [[ $3 =~ $intregex ]] ; then
 echo "Third argument must be an integer"
 exit 1
else
  echo  "Head:"
  head -$2 $1
  echo  "Tail:"
  tail -$3 $1
exit
fi
exit 1
fi
