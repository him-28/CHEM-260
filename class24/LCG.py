#!/usr/bin/python
m=2**8 # Modulus
a=29 # Multiplier
c=13 # Increment
X=11 # Seed
for i in range(100000):
    X=(a*X+c)%m
    print(X) 
