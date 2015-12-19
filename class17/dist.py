import sys
import math
def distance(p1, p2):
    if len(p1)!=len(p2): sys.exit("Vectors have different length")
    sum=0
    for i in range(len(p1)):
        sum+=(p1[i]-p2[i])**2
    return math.sqrt(sum)
