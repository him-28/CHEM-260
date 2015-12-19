assortments <- function(subtotal , availcoins ) {
    if (availcoins <= 1) return(1)
    count <- 0
    while (subtotal >= 0) {
        count = count + assortments(subtotal, availcoins-1)
        subtotal = subtotal - cointypes[availcoins]
    }
    return(count)
}
cointypes <- c(1, 5, 10, 25, 50, 100)
args <- commandArgs(trailingOnly=T)
if (length(args)==0) {
    stop("Enter an amount of money in cents")
}
amount = as.integer(args[1])
n <- assortments(amount , length(cointypes))
output <- sprintf("There are %d ways to carry $%d.%02d in coins\n",n,amount%/%100,amount%%100)
cat(output)



