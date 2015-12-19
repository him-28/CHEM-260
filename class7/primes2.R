is.prime <- function(n) {
    if (n<0) { return(FALSE) }
    if (n==1) { return(FALSE) }
    if (n==2) { return(TRUE) }
    max <- as.integer(sqrt(n)+1)
    for (i in 2:max) {
        if ((n%%i)==0) {
            return(FALSE)
        }
    }
    return(TRUE)
}
args <- commandArgs(trailingOnly=T)
if (length(args)!=1) {
    stop("You need to give one argument, n")
}
n <- as.integer(args[1])
range <- 1:n
primes <- range[sapply(range,is.prime)]
for (i in primes) {
    cat(i," ")
}
cat("\n")
