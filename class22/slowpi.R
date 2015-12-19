args <- commandArgs(trailingOnly=T)
if (length(args)!=1) {
    stop("You need to give one argument, trials")
}
ntrials <- as.integer(args[1])
start <- proc.time()
inside<-0
for (i in 1:ntrials) {
r<-runif(2)
if (sum(r^2)<1) {
inside<-inside+1 }
}
elapsed<-proc.time()-start
memo <- sprintf("pi.py: Ntrials=%d Error=%f Run time in seconds=%f\n",ntrials,(pi-4*inside/ntrials),elapsed[1])
cat(memo)
