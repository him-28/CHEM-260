dice <- function() {
    return(sum(sample(1:6,2,replace=TRUE)))
}
n.wins <- 0
n.trials <- 100000
for (i.trial in 1:n.trials) {
  point <- dice()
  if (point==7 || point==11) {
    n.wins <- n.wins+1
    next }
  if (point==2 || point==3 || point==12) {next}
  roll <- dice()
  while (roll != 7 && roll != point) {  
   roll <- dice() }
  if (roll == point) {n.wins <- n.wins+1}
}
win.ratio <- n.wins/n.trials
cat("win ratio=",win.ratio,"\n")
