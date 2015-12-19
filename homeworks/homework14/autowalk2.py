from __future__ import division
from random import choice
trials=100
steps=10000
gothome=0
for dim in range(1,11) :
    point=[0]*dim
    for i in range(trials):
        for step in range(steps):
            for j in range(dim):
                point[j]+=choice((-1,1))
            if point.count(0)==dim:
               gothome+=1
               break
    print "Fraction that got home=%f in %d dims" % (gothome/trials,dim)
f = open('out.text','w')
s = str(gothome/trials,dim)
f.write(s)
f.close()
