echo "First number please"
read num1
echo "Second number please"
read num2
let b=$num1+$num2
let b=b*7
echo "Result = " $b
o=`printf "(%d+%d)*7=%d\n" $num1 $num2 $(((num1+num2)*7))`
echo $o 
