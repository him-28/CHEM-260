#!/usr/bin/python
from random import choice
from math import sqrt
#from drawgridlib import drawgrid
npart=300
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
        # Stop if you are next to a particle
        if (grid[(x+1)%side][y]+grid[x][(y+1)%side]+
            grid[(x+side-1)%side][y]+grid[x][(y+side-1)%side])>0:
           # z = sqrt((((x+1)%side)-((x-1+side)%side))**2+(((y-1+side)%side)-((y+1)%side))**2)
            u = sqrt((x-side/2)**2+(y-side/2)**2)
            print "ipart: " , ipart , "distance: ", u
            break
#drawgrid(grid,side)
