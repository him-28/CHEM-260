#!/usr/bin/python
import sys
while 1:
    line=sys.stdin.readline() #Read next line from stdin into "line"
    print line, #Print line (comma avoids extra line feed)
    if line=="": #Quit while loop if line is empty
        break 
