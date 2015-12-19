d<-read.table("autowalk.out")
png("autowalk.png")
plot(d$V6~d$V8, type="l", ylab="Probability", xlab="No. of Dimensions")
dev.off()  
