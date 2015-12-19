class point:
    def __init__(self, dim, data):
        self.dim=dim
        self.data=[]
        for i in range(dim):
            self.data.append(float(data[i]))
    def printpoint(self):
        for i in self.data:
            print i, 
        print
    def scale(self, x):
        for i in range(self.dim):
            self.data[i]*=x
    def sqmag(self):
        sum=0
        for i in range(self.dim):
            sum+=self.data[i]**2
        print sum
    def dot(self, a):
        sum=0
        for i in range(self.dim):
            sum+=self.data[i]*a.data[i]
        return sum
    def add(self, y):
        sum=0
        for i in range(self.dim):
            self.data[i]+=y.data[i]
        
        
        
