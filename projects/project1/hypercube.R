#dists <- c()
means<-c()
n.trials <- 1000
dim<-1:30
n.dims <- 30
 for (i.dim in 1:n.dims) {
 dists<-c()
 for (i.trial in 1:n.trials) { 
# for (i.dim in 1:n.dims) {
 #n.curr<-1
 #n.next<-0
 #p1<-1/3*(i.dim^0.5)
 #p2<-((1/6*i.dim)^0.5)*((1/3*(1+2*(1-3/(5*i.dim))^0.5))^0.5)
 p1<-runif(i.dim)
 p2<-runif(i.dim) 
 dist<-sqrt(sum((p1-p2)^2))
 dists[i.trial]<-dist
#cat(dists,"\n")
#md<-mean(dists)
#cat("mean",md,"\n")
}
means[i.dim]<-mean(dists)
out<- sprintf("Mean distance at %d dim = %f ",i.dim, means[i.dim],"\n")
cat(out,"\n")
}
plot(means~dim)
#yma= max(means)
#ymi=min(means)
#plot(means[i.dim]~i.dim, type="l", ylim=c(ymi,yma))
#lines(means[i.dim]~i.dim, col=1:10000)

