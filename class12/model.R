rmr<-read.table("rmr.txt",header=T)
model<-lm(metabolic.rate~body.weight, data=rmr)
sum.model<-summary(model)
R2<-sum.model$r.squared
f<-sum.model$fstatistic
p.value<-pf(f[1],f[2],f[3],lower.tail=F)
output<-sprintf("R2 = %f and p-value=%f", R2, p.value)
write(output,file="model.out")
intercept<-model$coefficients[1]
slope<-model$coefficients[2]
output<-sprintf("slope=%f  intercept=%f",slope, intercept)
write(output,file="model.out",append=T)
png("graph.png")
plot(metabolic.rate~body.weight, data=rmr)
abline(model)
dev.off()
