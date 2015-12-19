from __future__ import division
from random import choice, random
from math import exp
state=0
nstates=4
states=[0]*nstates
T=3
ntrials=10000
for trial in range(ntrials):
    newstate=choice(range(nstates))
    x=exp(-(newstate-state)/T)
    if x>random():
        state=newstate
    states[state]+=1
for i in range(nstates-1,-1,-1):
    print "%d %6.3f"%(i,states[i]/ntrials)
