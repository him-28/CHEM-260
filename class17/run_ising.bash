t=1000
while [ $t -le 3000 ]; do
temp=`bc <<< "scale=2; $t/1000"`
Ising.py $temp
let t+=100
done
