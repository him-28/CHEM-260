from ising_class import *
ising1=ising(2.3, 20)
ising1.resetprops()
ising1.randomize()
ising1.printsys()
Temp=.5
while Temp<4.:
    ising1.changeTemp(Temp)
    ising1.trials(50000)
    ising1.resetprops()
    for i in range(100000):
        ising1.trial()
        ising1.addprops()
    ising1.calcprops()
    #ising1.printsys()
    Temp+=.2


