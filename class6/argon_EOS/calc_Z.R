data <- read.table("EOS_data.txt",header=F)
R <- 0.083145
M <- 39.948
T <- data$V1
P <- data$V2
rho.kgm3 <- data$V3
rho <- rho.kgm3/M
Z <- P/(rho*R*T)
P.atm <- P*1.01325

memo <- sprintf("   P(bar)    P(atm)    T(K)     rho(mol/L)        Z")
write(memo,"Z_data.out",append=FALSE)
for (i in 1:length(P)) {
    memo <- sprintf(" %8.4f   %8.4f  %8.4f  %8.4f     %8.4f",P[i],P.atm[i],T[i],rho[i],Z[i])
    write(memo,"Z_data.out",append=TRUE)
}
