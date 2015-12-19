from sudoku_class import *
asudoku=sudoku(9)
asudoku.generate()
for i in range(25,71):
    completed=0
    for j in range(1,51):
        asudoku.set_random(i)
        asudoku.solve()
        if asudoku.solved() :
            completed+=1
    print "value of n %d and percentage %d " %(i , completed*2)
    

