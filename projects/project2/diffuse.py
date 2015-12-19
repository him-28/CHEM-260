#!/usr/bin/python
from random import choice
from sys import argv, exit
if len(argv)==1:
    exit("Need to give density")
density=float(argv[1])
if density > 1.0 or density < 0.0 :
    exit("Density should lie between 0.0 to 1.0 ")
maxsteps=10000
npart=500
side=31  #Should be an odd number
time=0
steps = [(1,0),(-1,0),(0,1),(0,-1)]
grid=[[0 for x in range(side)] for y in range(side)]
for ipart in range(npart):
    # Start particle at center
    x,y = side/2,side/2
    perc=0
    # perform the random walk until particle departs
    for i in range(maxsteps):
        perc+=1
        grid[x][y]=0   #Remove particle from current spot
        # Randomly move particle
        sx,sy = choice(steps)
        x += sx
        y += sy
        if x<0 or y<0 or x==side or y==side:
            time+=perc
            break
        grid[x][y]=1   #Put particle in new location
avetime=float(time)/npart
print "<t>=%5.2F <t>/r2=%5.2f"%(avetime, avetime/(side**2))
