r <- list()
for (i in 1:10) {
r[[i]] <- sample(1:6,i,replace=TRUE)
}
for (i in r) {
cat(i,"\n")
}
rsum <- sapply(r,sum)
cat("sums=",rsum,"\n")
rmean <- sapply(r,mean)
cat("means=",rmean,"\n")
rmax <- sapply(r,max)
cat("maxs=",rmax,"\n")
