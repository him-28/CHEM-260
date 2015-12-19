seqs<-c("CAG","CCG","CGG","CTG","GAC","GCC","GGC","GTC")
setwd("../homework10_11")
png("DNA_rmsd.png")
flag<-TRUE
icolor<-2
for ( seq in seqs ) {
 setwd(seq)
 if (file.exists("rmsd.xvg")) {
 data<-read.table("rmsd.xvg", header=F, skip=13)
 #prefix<-"DNA_rmsd"
 suffix<-"png"
 fn <- sprintf("%s.%s",seq,suffix) 
 ymin<-min(data$V2)
 ymax<-max(data$V2)
 setwd("../")
 if(flag==TRUE) {
 plot( data$V2~data$V1, type="l", ylim=c(ymin, ymax), lwd=0.3 ) 

 flag<-FALSE
 #dev.off()
} else {
  #ggplot(data$V2~data$V1, aes(y=c(ymin, ymax))) + geom_point()
 lines(data$V2~data$V1, col=icolor)
 icolor<-icolor+1
 } 
  #dev.off() 
  setwd(seq)
  #cat(setwd(seq),"\n")
  } else {
 cat("rmsd.xvg not found in ",seq,"\n")
 }
  
  setwd("../")
}
  setwd("../")
dev.off()
