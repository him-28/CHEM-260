cs<-read.table("out1.txt")
png("graph1.png") 
plot(cs$V7~cs$V3, type="l", col=3)
dev.off()
