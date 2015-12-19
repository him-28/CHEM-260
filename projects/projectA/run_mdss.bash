#!/bin/bash
if [ ! -f MDSS.py ]
then
echo "Cannot find MDSS.py"
exit 1
fi
if ! [[ $# -eq 4 ]] ; then
 echo "Script takes 4 arguments "
 exit 1
fi
intregex='^[0-9]+$'
if ! [[ $1 =~ $intregex ]] ; then
 echo "All arguments must be integers"
 exit 1
fi
if ! [[ $2 =~ $intregex ]] ; then
 echo "All arguments must be integers"
 exit 1
fi
if ! [[ $3 =~ $intregex ]] ; then
 echo "All arguments must be integers"
 exit 1
fi
if ! [[ $4 =~ $intregex ]] ; then
 echo "All arguments must be integers"
 exit 1
fi
if [ $1 -gt 2000 -o $1 -lt 500 ] ; then
echo "Parameters out of range"
exit 1
fi
if [ $2 -gt 2000 -o $2 -lt 500 ] ; then
echo "Parameters out of range"
exit 1
fi
if [ $3 -gt 1100 -o $3 -lt 100 ]; then
echo "Parameters out of range"
exit 1
fi
if [ $4 -gt 1100 -o $4 -lt 100 ]; then
echo "Parameters out of range"
exit 1
fi
for (( i = $1; i <= $2; i+=100 ))      ### Outer for loop ###
do
    for (( j = $3; j <= $4; j+=100 )) ### Inner for loop ###
    do
          echo -n "$i $j "
	  MDSS.py $i $j | grep pressure | colrm 1 17
    done
done
