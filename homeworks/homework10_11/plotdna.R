seqs<-c("CAG","CCG","CGG","CTG","GAC","GCC","GGC","GTC")
setwd("../homework10_11")
for ( seq in seqs ) {
 setwd(seq)
 if (file.exists("rmsd.xvg")) {
 data<-read.table("rmsd.xvg", header=F, skip=13)
 suffix<-"png"
 fn <- sprintf("%s.%s",seq,suffix)
 cat(fn,"\n")
 png(fn)
 plot(data$V2~data$V1, type="l")
 dev.off()
 #cat("Final rms for",seq," is ",data$V2[500],"\n")
 } else {
 cat("rmsd.xvg not found in ",seq,"\n")
 }
 setwd("../")
}
