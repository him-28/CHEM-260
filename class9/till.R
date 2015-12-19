#R Program to Monte Carlo stem cell proliferation model
stem.cells <- c(0)
n.trials <- 10000
n.gens <- 7
p.div <- 0.6
for (i.trial in 1:n.trials) {   # Loop over Monte Carlo Trials  
  n.stem.curr <- 1
  n.stem.next <- 0
  for (i.gen in 1:n.gens) {     # Loop over generations
    for (i.cell in 1:n.stem.curr) {
      if (p.div > runif(1)) {
        n.stem.next <- n.stem.next+2
      }
    }
    n.stem.curr <- n.stem.next
    n.stem.next <- 0
    if (n.stem.curr==0) {
      break
    }
  }
  stem.cells[i.trial] <- n.stem.curr
}
hist(stem.cells, breaks=50)
output<-sprintf("Mean # cells at %3d gens=%7.2f\n",n.gens, mean(stem.cells))
cat(output)
