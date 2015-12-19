args <- commandArgs(trailingOnly=T)
if (length(args)!=1) {
    stop("You need to give one argument, trials")
}
ntrials <- as.integer(args[1])
start <- proc.time()
counter<-0
x<-runif(ntrials)
y<-runif(ntrials)
r2<-x^2+y^2
inside<-sum(r2<1)
elapsed<-proc.time()-start
memo <- sprintf("fastpi.py: Ntrials=%d Error=%f Run time in seconds=%f\n",ntrials,(pi-4*inside/ntrials),elapsed[1])
cat(memo)

