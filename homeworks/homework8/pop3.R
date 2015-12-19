if (interactive()) {
 if (!exists("P") && !exists("r") && !exists("K")) {
 stop("You need to set P, r, and K")
 } 
} else {
 args <- commandArgs(trailingOnly=T)
 if (length(args)!=3) {
 stop("You need to give 3 arguments P, r, and K")
 }
 P<-as.numeric(args[1])
 r<-as.numeric(args[2])
 K<-as.numeric(args[3])
}
pop<-P
pop.hist<-c()
for (i in 1:150) {
 pop.hist[i]<-pop
 pop<-pop*exp(r*(1-pop/K))
}
png("pop_graph.png")
plot(pop.hist)
dev.off()
