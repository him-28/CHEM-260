pops <- read.table("ipd_pop.txt",header=T)
name.list <- names(pops)
pops[1,]
ymax=max(pops)
ymin=min(pops)
plot(pops[,1],type="l",col=1,ylim=c(ymin,ymax),lwd=2,ylab="Population",xlab="Generation")
for (i in seq(2,length(name.list))) {
    lines(pops[,i],col=i,lwd=2)
}
