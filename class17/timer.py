import time
start=time.clock()
for i in xrange(10000000):
     j=i*i
print "elapsed time: ",time.clock()-start
