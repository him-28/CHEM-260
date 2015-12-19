Sm<-14000
Sf<-9000
Im<-1000
If<-1000
Gm<-0.05
Gf<-0.007
Am<-0.000006  #,0.000002)
Am2<-0.000002
Af<-0.0000009
Sm.hist<-c()
Im.hist<-c()
#Gm.hist<-c()
Sf.hist<-c()
If.hist<-c()
#Gf.hist<-c()
#day<-1:2000
#for (val in Am) {

for (day in 1:2000) {
	Sm.hist[day]<-Sm
	Im.hist[day]<-Im
	#Gm.hist[day]<-Gm
	Sf.hist[day]<-Sf
        If.hist[day]<-If
        #Gm.hist[day]<-Gf
        # You need to add next three lines from notes
	delta.Sm <- Gm*(Im-Am)*Sm*If #(-alpha*S*I)
	delta.Im <- Am*Sm*(If-Gm)*Im #alpha*S*I-gamma*I
        delta.Sf <- Gf*(If-Af)*Sf*Im
        delta.If <- Af*Sf*(Im-Gf)*If
	#delta.R <- gamma*I
	Sm<-Sm+delta.Sm
	Im<-Im+delta.Im
        Sf<-Sf+delta.Sf
        If<-If+delta.If
	#R<-R+delta.R
	# Ensure S,I,R > 0
	Sm<-max(Sm,0) 
	Im<-max(Im,0)
        Sf<-max(Sf,0)
        If<-max(If,0)
}
png("plot1.png")   
plot(If.hist, type="l")
lines(Sf.hist,  col=2)
#lines(Gf.hist, col=3, ylim=c(NA,3), xlim=c(NA,3) )
plot(Im.hist, type="l", col=5)
lines(Sm.hist,  col=3)
#lines(If.hist,  col=2)
dev.off()


Sm<-14000
Sf<-9000
Im<-1000
If<-1000
Gm<-0.05
Gf<-0.007
Am2<-0.000002
Af<-0.0000009
for (day1 in 1:2000) {
        Sm.hist[day1]<-Sm
        Im.hist[day1]<-Im
        #Gm.hist[day1]<-Gm
        Sf.hist[day1]<-Sf
        If.hist[day1]<-If
        #Gm.hist[day]<-Gf
        # You need to add next three lines from notes
        delta.Sm <- Gm*(Im-Am2)*Sm*If #(-alpha*S*I)
        delta.Im <- Am2*Sm*(If-Gm)*Im #alpha*S*I-gamma*I
        delta.Sf <- Gf*(If-Af)*Sf*Im
        delta.If <- Af*Sf*(Im-Gf)*If
        #delta.R <- gamma*I
        Sm<-Sm+delta.Sm
        Im<-Im+delta.Im
        Sf<-Sf+delta.Sf
        If<-If+delta.If
        #R<-R+delta.R
        # Ensure S,I,R > 0
        Sm<-max(Sm,0)
        Im<-max(Im,0)
        Sf<-max(Sf,0)
        If<-max(If,0)
}
png("plot2.png") 
plot(If.hist, type="l")
#lines(If.hist, col=4)
#lines(Gf.hist, col=3, ylim=c(NA,3), xlim=c(NA,3) )
lines(Sf.hist, col=4)
plot(Im.hist, type="l",  col=3)
lines(Sm.hist,  col=2)
#lines(Gm.hist, col=3, ylim=c(NA,3), xlim=c(NA,3))
dev.off()
