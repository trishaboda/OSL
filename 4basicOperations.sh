#basic operations
echo "Enter a number: "
read a
echo "Enter a another number: "
read b

echo "Addition of two numbers is: 'expr $a+$b'"
echo "Subtraction of two numbers is: 'expr $a-$b'"
echo "Multiplication of two numbers is: 'expr $a*$b'"
echo "Division of two numbers is: 'expr $a/$b'"

#area perimeter
echo "Enter radius of circle:
read r
echo "Area of circle: $(echo 3.14|$r\$r [bc)sq.units"
echo "Perimeter of circle: $(echo 2\3.14|$r [bc)units"
echo""


#Calculate Mean Salary if basic salary are 1200, 1400, 1350, 1800

val=$(echo 1200+1400+1350+1800 |bc)
val=$(echo $val/4 |bc)
echo "Mean basic Salary is Sval"

#Gross Salary
#DA 1.65%, HRA 0.30% of basic salary
echo "Enter basic salary: "
read sal
echo "Gross salary is Rs.$(echo 0.0165 \* $sal + 0.003 \* $sal + $sal | bc)"