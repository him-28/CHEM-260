pop<-100 
pop.hist<-c() 
r<-0.05 
for (i in 1:150) {  
     pop.hist[i]<-pop  
     delta.pop<-r*pop  
     pop<-pop+delta.pop 
} 
plot(pop.hist)
