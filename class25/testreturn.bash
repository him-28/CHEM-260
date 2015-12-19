#!/bin/bash
testreturn <<< $1
if [ $? -eq 0 ]; then
 echo " Worked"
else
 echo " Failed"
fi 
