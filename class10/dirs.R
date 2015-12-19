for (i in 1:5) {
dirname<-sprintf("level%02d",i)
dir.create(dirname)
setwd(dirname)
}
