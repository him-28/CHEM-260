from __future__ import division
from random import choice
total=0
for i in range(1000):
    total+=choice(range(1,7)) # Must be indented
print "Average roll=%f"%(total/1000)
