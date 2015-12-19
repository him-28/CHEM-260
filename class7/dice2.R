args <- commandArgs(trailingOnly=T)
if (length(args)!=1) {
stop("You need to give one argument, ndice")
}
ndice <- as.integer(args[1])
rolls<-1:6
nrolls<-10000
total<-0
for (i in 1:nrolls) {
roll<-
sum(sort(sample(rolls,ndice,replace=TRUE),decreasing=TRUE)[1:2])
total<-total+roll
}
cat("Average score",total/nrolls,"\n")
