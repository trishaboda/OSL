#check two strings are equal or not
echo "Enter string 1: "
read a
echo "Enter string 2: "
read b

if ["$a" == "$b"] ; then
	echo "Strings are equal"
else 
	echo "Strings are not equal"
fi

#concatenation
concat=$a$b
echo "Concatenated string is $concat "

#find the length of string
length=${#concat}
echo "Length of concatenated string is $length"