#! /bin/bash

# This is a shell script which you can use to test your code
# To provide input, you can pipe text to standard input, which will be read by scanf

# `echo` just prints out whatever its command-line arguments are, and
# the `|` pipes the output of one command to the input of another.
#echo "10 + 5" | ./problem1

ERR="error"
result=`echo "10 + 5" | ./problem1`
if [ $result != "15.0000000000000" ]; then echo "Test failed, expected 15.000000 but got $result."; fi

# You can check the results with the following scripting magic:
result=`echo "2 - 90" | ./problem1`
if [ $result != "-88.0000000000000" ]; then echo "Test failed, expected -88.000000 but got $result."; fi

result=`echo "56.32 * 23.96" | ./problem1`
if [ $result != "1349.4272000000001" ]; then echo "Test failed, expected 1349.4272000000001 but got $result."; fi

result=`echo "9 / 0" | ./problem1`
if ! [[ $result == *$ERR* ]]; then echo "Test failed, expected $ERR but got $result."; fi

result=`echo "9 / -32" | ./problem1`
if [ $result != -0.2812500000000 ]; then echo "Test failed, expected -0.281250 but got $result."; fi

result=`echo "2 ^ 10" | ./problem1`
if [ $result != 1024.0000000000000 ]; then echo "Test failed, expected 1024.000000 but got $result."; fi

result=`echo "0 ^ -32" | ./problem1`
if ! [[ $result == *$ERR* ]]; then echo "Test failed, expected $ERR but got $result."; fi

result=`echo "0 ^ 0" | ./problem1`
if ! [[ $result == *$ERR* ]]; then echo "Test failed, expected $ERR but got $result."; fi

result=`echo "-3 ^ 2.79" | ./problem1`
if ! [[ $result == *$ERR* ]]; then echo "Test failed, expected $ERR but got $result."; fi

result=`echo "-3 ? 2.79" | ./problem1`
if ! [[ $result == *$ERR* ]]; then echo "Test failed, expected $ERR but got $result."; fi

result=`echo "5 * four" | ./problem1`
echo $result
if ! [[ $result == *$ERR* ]]; then echo "Test failed, expected $ERR but got $result."; fi

result=`echo "17.9898222131 - 1.8989822282201" | ./problem1`
if ! [[ $result == "16.0908399848799" ]]; then echo "Test failed, expected 16.0908399848799 but got $result."; fi
# Add more test cases as necessary


