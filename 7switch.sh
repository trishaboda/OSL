#!bin/bash
#check if a number is 1/2/3 digit

echo "Enter a number: "
read n

case $n in

[0-9])
echo "$n is a single digit number."
;;

[0][0-9])
n="${n#0}"
echo "$n is a single digit number."
;;

[1-9][0-9])
echo "$n is a double digit number."
;;

[1-9][0-9][0-9])
echo "$n is a triple digit number."
;;

*)
echo "$n is greater than 999."
;;

esac