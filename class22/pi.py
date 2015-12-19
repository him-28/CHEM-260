#!/usr/bin/python
import sys
import random
import math
import time

# Set number of trials
if (len(sys.argv)<2):
    sys.exit("Usage: pi.py [number of trials], e.g. pi.py 1000")

start=time.clock()
inside=0
trials=int(sys.argv[1])
for i in range(trials):
    x=random.random()
    y=random.random()
    if (x*x+y*y)<1.0:
        inside+=1

pi=4.*float(inside)/float(trials)
elapsed=time.clock()-start
print "Pi.py: Ntrials=%d Error=%8.5f Run time (seconds)=%f"%(pi,pi-math.pi,elapsed)

    
