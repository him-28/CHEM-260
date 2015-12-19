#!/bin/bash
if [ ! -f pi.py ]
then
echo "Trouble, could not find input file pi.py"
exit 1
fi
if [ ! -x pi.py ]
then
echo "pi.py is not executable"
exit 1
fi
if [ $# -lt 1 ]
then
echo "One argument needed, no arguement found"
exit 1
fi
for i in $*
do
if [ -d $i ]; then
echo "Directory named $1 already exists"
exit 1
else
  mkdir $i
  echo "Okay I made a directory named $i"
fi
cd $i
if [  -f pi.out ]; then
echo "pi.out already exist"
rm -r pi.out
else
   for j in {1..10}
   do
   ../pi.py $i  >> pi.out
   done 
   wc pi.out
cd ..
echo -n "total word count of all pi.out:"
find -name "pi.out" | wc
exit 1
fi
done
