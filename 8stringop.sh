#print odd-position characters
echo "Enter a string to find odd position characters: " 
read input_string

length=${#input_string}

for (( i=0; i<$length; i+=2 )); do
    echo -n "${input_string:i:1}"
echo " " 
done


#find whether a given string is a palindrome or not
echo "Enter a String to check for palindrome: "
read a
reverse=""
len=${#a}
for (( i=$len-1; i>=0; i-- ))
do 
	reverse="$reverse${a:$i:1}"
done
if [ $a == $reverse ]
then
    echo "$a is palindrome"
else
    echo "$a is not palindrome"
fi
echo " "


#print the reverse of the given string
echo "Enter a String to reverse: "
read a
reverse=""

len=${#a}
for (( i=$len-1; i>=0; i-- ))
do 
	reverse="$reverse${a:$i:1}"
done
echo "$reverse"
echo " "


#find the occurence of a character in the string 
echo "Enter a string to check occurence of a character: " 
read input_string
echo "Enter a character to find its occurrences: " 
read character

count=0

for (( i=0; i<${#input_string}; i++ )); do
    if [ "${input_string:$i:1}" == "$character" ]; then
        ((count++))
    fi
done
echo "The character '$character' occurs $count time(s) in the string."
echo " "


#shell script using switch case statement to print whether the character entered by the user is a vowel or consonant
echo "Enter a character to check vowel or consonant: " 
read char

case $char in
    [aeiouAEIOU]) echo "$char is a vowel.";;
    [a-zA-Z]) echo "$char is a consonant.";;
    *) echo "$char is not a valid alphabet character.";;
esac