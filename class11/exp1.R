d<-read.table("data.txt")
png("e1.png")
plot(d$V2~d$V1, pch=1, ylab="Temp", xlab="Time") #Change plot symbol
plot(d$V2~d$V1, pch=2, col=2, ylab="Temp", xlab="Time") #Change plot symbol
plot(d$V2~d$V1, pch=5, col=3, ylab="Temp", xlab="Time") #Change plot symbol
dev.off()
png("e2.png")
plot(d$V2~d$V1, pch=1, ylab="Temp", xlab="Time") #Change plot symbol
dev.off()
png("e3.png")
plot(d$V2~d$V1, pch=2, col=2, ylab="Temp", xlab="Time") #Change plot symbol
dev.off()
png("e4.png")
plot(d$V2~d$V1, pch=5, col=3, ylab="Temp", xlab="Time") #Change plot symbol
dev.off()

