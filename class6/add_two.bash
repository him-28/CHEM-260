#!/bin/bash
echo -n "Enter a number: ";read n1
echo -n "Enter another number: ";read n2
let n3=n1+n2
output=`printf "%d+%d=%d\n" $n1 $n2 $n3`
echo $output