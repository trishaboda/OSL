#Even or odd number check
echo "Checking if entered number is Even or Odd"
echo "Enter a number:"
read num
if [ $num -eq 0 ]
then
    echo "The number is neither odd nor even"
elif [ $((num%2)) -eq 0 ]
then 
    echo "$num is Even!"
else
    echo "$num is Odd!"
fi
echo " "


#Largest of three numbers
echo "Checking Largest of three numbers"
echo "Enter number 1:"
read num1
echo "Enter number 2:"
read num2
echo "Enter number 3:"
read num3

if [ $num1 -ge $num2 ]
then 
    if [ $num1 -ge $num3 ]
    then
        echo "$num1 is the greatest"
    else
        echo "$num3 is the greatest"
    fi
else
    if [ $num2 -ge $num3 ]
    then
        echo "$num2 is the greatest"
    else
        echo "$num3 is the greatest"
    fi
fi
echo " "


#Checking if leap year
echo "Checking if the entered year is a leap year"
echo "Enter Year:"
read year
if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]
then
    echo "$year is a leap year"
else
    echo "$year is not a Leap Year"
fi
echo " "


#Balance-Withdraw-Tax
echo "Calculating Account Balance"
echo "Enter account balance: "
read bal
echo "Enter withdrawal amount: "
read withdraw

if [ $withdraw -ge $bal ]
then
	echo "Insufficient Balance, Cannot Withdraw!"
	exit
fi

if [ $withdraw -lt 1500 ]
then
	tax=$(echo "0.03 * $withdraw" | bc)
	res=$(echo "$withdraw - $tax" | bc)
	bal=$(echo "$bal - $res" |bc)
	echo "Tax Deduction: Rs.$tax"
	echo "Amount Withdrawn: RS.$res"
	echo "Net Balance: Rs.$bal"

elif [ $withdraw -gt 3000 ] && [ $withdraw -lt 3000 ]
then 
	tax=$(echo "0.04 * $withdraw" | bc)
	res=$(echo "$withdraw - $tax" | bc)
	bal=$(echo "$bal - $res" |bc)
	echo "Tax Deduction: Rs.$tax"
	echo "Amount Withdrawn: RS.$res"
	echo "Net Balance: Rs.$bal"
	
else
	tax=$(echo "0.05 * $withdraw" | bc)
	res=$(echo "$withdraw - $tax" | bc)
	bal=$(echo "$bal - $res" |bc)
	echo "Tax Deduction: Rs.$tax"
	echo "Amount Withdrawn: RS.$res"
	echo "Net Balance: Rs.$bal"
fi
echo " "