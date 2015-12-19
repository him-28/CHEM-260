png("plot_pk.png")
pk1<-read.table("pk_rmsd.txt",header=T)
y.min<-min(pk1[,2:5])
y.max<-max(pk1[,2:5])
plot(pk1$ChainA~pk1$Time,type="l",ylim=c(y.min,y.max),ylab="RMSD")
for (i in 3:5) {
lines(pk1[,i]~pk1$Time, col=i)
}
dev.off()
