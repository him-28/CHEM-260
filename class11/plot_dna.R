png("dna.png")
for (i in 1:3) {
fn <- sprintf("dna%1d.txt",i)
data <- read.table(fn, skip=13)
if (i==1) {
plot(data$V2~data$V1,type="l")
} else {
lines(data$V2~data$V1,col=i)
}
}
dev.off()
