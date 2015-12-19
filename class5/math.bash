#!/bin/bash
let a=4*12
echo $a
let b=a+15
let b++
let b*=2
echo $b
let c=b%6
#Remainder after division by 6
echo $c
let "d = c * 5" #Use quotes if you want to use spaces
echo $d
