#!/usr/bin/python
from sys import argv, exit
if len(argv)==1:
    exit("Need to give sequence as argument")
if len(argv)>2:
    exit("Need to give only one sequence as argument")
code = {"H":1.00794, "C":12.0107, "N":14.00674, "O":15.9994, "P":30.973761, "S":32.066}
#print code["H"]
seq=argv[1]
def molemass(seq):
    protein=0.0
    if len(seq)==1:
        exit("Need to give a sequence as argument")
    for i in seq:
        i = i.upper()
        if i in code:
            protein+= code[i]
    	else:
            exit("Key not found")
    return protein
print "Molecular Mass:",molemass(seq)
