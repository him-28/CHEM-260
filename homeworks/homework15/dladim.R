d<-read.table("dladim.out")
N<-log(d$V1)
L1<-log(d$V2)
L2<-log(d$V3)
d1<-read.table("dladim2.out")
model<-lm(V3~V2, data=d1)
intercept<-model$coefficients[1]
slope<-model$coefficients[2]
output<-sprintf("slope=%f intercept=%f",slope, intercept)
cat(output,"\n")
model<-lm(log(V1)~log(V2), data=d)
intercept<-model$coefficients[1]
slope<-model$coefficients[2]
output<-sprintf("slope=%f intercept=%f",slope, intercept)
cat(output,"\n")
png("dladim.png")
plot(L2~L1, type="l", ylab="log(N)", xlab="log(L)")
lines(N~L1, col=333)
dev.off()  
