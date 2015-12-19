from __future__ import division
from random import choice
dim=3
trials=100
steps=10000
gothome=0
for i in range(trials):
    point=[0]*dim
    for step in range(steps):
         point[choice(range(dim))]+=choice((1,-1))
         if point.count(0)==dim:
            gothome+=1
            break
print "Fraction that got home=%f in %d dimensions" % (gothome/trials,dim)
            
            
