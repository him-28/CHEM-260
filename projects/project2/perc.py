#!/usr/bin/python
from random import choice, random
from sys import argv, exit
if len(argv)==1:
    exit("Need to give density")
density=float(argv[1])
if density > 1.0 or density < 0.0 :
    exit("Density should lie between 0.0 to 1.0 ")
maxsteps=4950
npart=500
side=31  #Should be an odd number
time=0
perc=0
steps = [(1,0),(-1,0),(0,1),(0,-1)]
grid=[[0 for x in range(side)] for y in range(side)]
for ipart in range(npart):
    # Start particle at center
    x,y = side/2,side/2
    counter=0
    pc=0
    for i in range(side):
        for j in range(side):
            if density > random() :
                grid[i][j]=1
    # perform the random walk until particle departs
    for i in range(maxsteps):
        counter+=1
        grid[x][y]=0   #Remove particle from current spot
        # Randomly move particle
        sx,sy = choice(steps)
        x += sx
        y += sy
        
        if x==0 or y==0 or x==side-1 or y==side-1:
            perc+=1
            time+=counter
            #perc+=pc
            
            break
        if grid[x][y]==1:
            continue
        grid[x][y]=1   #Put particle in new location
avetime=float(time)/npart
print "<t>=%5.2F <t>/r2=%5.2f probability=%5.2f density=%5.2f"%(avetime, avetime/(side**2), float (perc/npart), density)
