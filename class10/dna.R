seqs<-c("CAG","CCG","CGG","CTG","GAC","GCC","GGC","GTC")
setwd("dna_data")
for ( seq in seqs ) {
setwd(seq)
if (file.exists("rmsd.xvg")) {
data<-read.table("rmsd.xvg", header=F, skip=13)
cat("Final rms for",seq," is ",data$V2[500],"\n")
} else {
cat("rmsd.xvg not found in ",seq,"\n")
}
setwd("../")
}
