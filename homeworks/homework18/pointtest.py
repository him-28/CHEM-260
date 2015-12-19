from point import *
p1=point(3, [1., 2., 3.])
p1.printpoint()
#p1.scale(3.3)
p1.sqmag()
p2=point(3, [6., 7., 8.])
p2.printpoint()
#p1.scale(3.3)
p2.sqmag()
print "p1 dot p2=", p1.dot(p2)
print "p1 add p2=",
p1.add(p2)
p1.printpoint()
