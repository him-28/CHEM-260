from math import sqrt
from drawtraj import drawtraj
def force(x,y,m,msun):
    r2=x**2+y**2
    r32=r2*sqrt(r2)
    fx=-x*m*msun/r32
    fy=-y*m*msun/r32
    return fx,fy
def integrate(x,y,vx,vy,fx,fy,m,dt):
    ax,ay=fx/m,fy/m
    vx+=ax*dt
    vy+=ay*dt
    x+=vx*dt
    y+=vy*dt
    return x,y,vx,vy
# Main part of the program
msun=100
mstar=300000
m=1
nsteps=100000
dt=0.01
r=50
x,y=0,r
x1,y1=0,r
vx1,vy1=1.2,0
vx,vy=1.2,0
trajx,trajy=[],[]
starx,stary=[],[]
for t in range(nsteps):
    fx,fy=force(x,y,m,msun)
    fx1,fy1=force(x,y,m,mstar)
    x,y,vx,vy=integrate(x,y,vx,vy,fx,fy,m,dt)
    x1,y1,vx1,vy1=integrate(x1,y1,vx1,vy1,fx1,fy1,m,dt)
    trajx.append(x)
    trajy.append(y)
    starx.append(x1)
    stary.append(y1)
drawtraj(trajx,trajy,starx,stary,6*r)
