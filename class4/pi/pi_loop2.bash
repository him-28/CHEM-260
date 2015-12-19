#!/bin/bash
if [ ! -f pi.py ]
then
echo "Trouble, could not find input file pi.py"
exit 1
fi
if [ $# -lt 1 ]
then
echo "One argument needed, no arguement found"
exit 1
fi
for i in $*
do
mkdir $i
cd $i
for j in {1..10}
do
../pi.py $i >> pi.out
done
cd ..
done
