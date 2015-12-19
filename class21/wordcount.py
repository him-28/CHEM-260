#!/usr/bin/python
import sys
from collections import Counter
words=[]
while 1:
    line=sys.stdin.readline() #Read next line from stdin into "line"
    print line, #Print line (comma avoids extra line feed)
    if line=="": #Quit while loop if line is empty
        break
    words.extend(line.split())
words_lower=[]
for i in words:
    words_lower.append(i.lower())
words=words_lower 
counts=Counter(words)
for i in counts:
    print "%2d: %s"%(counts[i],i) 
