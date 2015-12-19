p<-matrix(0,3,3)
p[1,1]<-.11
p[1,2]<-.15
p[1,3]<-.15
p[2,1]<-0.3
p[3,2]<-0.6
p[3,3]<-0.6
print(p)
s<-matrix(0,3,1)
s[1,1]<-50
s[2,1]<-10
s[3,1]<-25
cat("Initial pops",s,"\n")
for (i in 1:20) {
 s<-p%*%s
}
cat("Final pops",s,"\n") 
