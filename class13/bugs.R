p<-matrix(0,3,3)
p[1,3]<-100
p[2,1]<-0.15
p[3,2]<-0.1
p[3,3]<-0.4
print(p)
s<-matrix(0,3,1)
s[1,1]<-10
cat("Initial pops",s,"\n")
for (i in 1:25) {
s<-p%*%s
}
cat("Final pops",s,"\n")
