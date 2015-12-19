lcg<-read.table("LCG.out")$V1
n<-length(lcg)
x<-lcg[seq(1,n,2)]
y<-lcg[seq(2,n,2)]
plot(y~x)

    
