#!/bin/bash
if [ $# -ne 1 ]; then
   echo "This script requires a protein file"
   exit 1
fi
if [ ! -f $1 ]; then
    echo "Cannot find protein file"
    exit 1
fi
for i in CYS GLU GLN GLY HIS ALA ARG ASN ASP ILE LEU LYS MET PHE PRO SER THR TRP TYR VAL
do
echo -n "The number of $i amino acids in $1 is:"
grep $i $1 | grep CA | wc | colrm 10 
done
echo "Sorted Count in Decreasing Order of WC"
if [ -f out.txt ]
then
rm out.txt
fi
for i in CYS GLU GLN GLY HIS ALA ARG ASN ASP ILE LEU LYS MET PHE PRO SER THR TRP TYR VAL
do
echo -n "Count of $i in $1 :" >> out.txt
#printf "The number of %s amino acids in %s is:" $i $1 > out.txt
grep $i $1 | grep CA | wc | colrm 10 >> out.txt
done
sort -n -k7 -r  out.txt

