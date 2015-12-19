if (interactive()) {
 limit<-1000
 
} else {
 args <- commandArgs(trailingOnly=T)
 if (length(args)!=1) {
 stop("You need to give one argument, limit")
 }
 limit <- as.integer(args[1])
}
seqlen<-c()
seqmax<-c()
for (i in 1:limit) {
n<-i
maxval<-0
counter<-1

while (n != 1) {
cat(n,"\n")

 if (n%%2==0) {
 n<-n/2
 } else {
 n<-3*n+1

 }
counter<-counter+1
if(n>maxval){
maxval<-n
}
}
seqmax<-append(seqmax,maxval)
seqlen<-append(seqlen, counter)
cat("Max:",seqmax,"\n")
}
png("seqlen.png")
plot(seqlen)
dev.off()
png("seqmax.png")
plot(seqmax)
dev.off()
