#!/usr/bin/python
import math
from random import choice
from math import exp
#from drawgridlib import drawgrid
npart=300
count=0
f = open("dladim.out","w")
h = open("dladim2.out","w")
side=75  #Should be an odd number
steps = [(1,0),(-1,0),(0,1),(0,-1)]
grid=[[0 for x in range(side)] for y in range(side)]
grid[side/2][side/2]=1
for ipart in range(npart):
    # Start particle at origin
    x,y = 0,0
    # perform the random walk until particle aggregates
    while 1:
        grid[x][y]=0   #Remove particle from current spot
        # Randomly move particle
        sx,sy = choice(steps)
        x += sx
        y += sy
        # Enforce periodic boundaries
        if x < 0: x=side-1
        if y < 0: y=side-1
        if x==side: x=0
        if y==side: y=0
        grid[x][y]=1   #Put particle in new location 
        #count = count+1
        # Stop if you are next to a particle
        if (grid[(x+1)%side][y]+grid[x][(y+1)%side]+
            grid[(x+side-1)%side][y]+grid[x][(y+side-1)%side])>0:
            #print "count:" , count
            break
#drawgrid(grid,side)
for L in range(1,side/2+1):
    if (grid[(L+1)%side][L]+grid[L][(L+1)%side]+grid[(L+side-1)%side][L]+grid[L][(L+side-1)%side])>0:
        count=count+1
        #print "count" , count
    N = exp(2*math.log(L))
    try:
        c = math.log(count)
    except ValueError:
        c=0
    b = math.log(N)
    print "Formula value of N :", N ,"\t Value of L: ",L , "\t Value of N by counting cell occupied: ",count
    f.write(str(L) + " " + str(N) + " " + str(count) + "\n")
    h.write(str(L) + " " + str(b) + " " + str(c) + "\n")
f.close()
h.close()
