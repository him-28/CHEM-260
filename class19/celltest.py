from ising_class import *
acell=cell(3,3,10) #Args: n, i, j
print acell.cellspin()
acell.spin.flip() #Reaching through cell to inner spin object
print acell.left #Directly accessing the neighbor indices
print acell.right
print acell.up
print acell.down
