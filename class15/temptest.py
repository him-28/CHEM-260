#!/usr/bin/python
from sys import argv, exit
if len(argv)==1:
   exit("Need to give temperature")
Temp=int(argv[1])
if Temp > 100:
     print "Too Hot"
elif Temp < 0:
     print "Too Cold"
else:
     print "Just Right" 
