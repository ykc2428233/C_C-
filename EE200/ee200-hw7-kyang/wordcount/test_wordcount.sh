#! /bin/bash

# Put whatever tests you want here, e.g., 
# echo "words, words, words" | ./wordcount

echo "words, words, words" | ./wordcount

./wordcount -l -w -c ../README.md
./wordcount -l ../README.md
./wordcount -w ../README.md
./wordcount -c ../README.md
./wordcount -l -w ../README.md
./wordcount -l -c ../README.md
./wordcount -w -c ../README.md
./wordcount ../README.md


echo "Hello \n world! \n lololololololololo." | ./wordcount -l -w -c 
echo "Hello \n world! \n lololololololololo." | ./wordcount -l 
echo "Hello \n world! \n lololololololololo." | ./wordcount -w 
echo "Hello \n world! \n lololololololololo." | ./wordcount -c 
echo "Hello \n world! \n lololololololololo." | ./wordcount -l -w 
echo "Hello \n world! \n lololololololololo." | ./wordcount -l -c 
echo "Hello \n world! \n lololololololololo." | ./wordcount -w -c 
echo "Hello \n world! \n lololololololololo." | ./wordcount 


echo "Hello \n world! \n   lololololololololo." | ./wordcount -l -w -c 
echo "Hello \n world! \n   lololololololololo." | ./wordcount -l 
echo "Hello \n world! \n   lololololololololo." | ./wordcount -w 
echo "Hello \n world! \n   lololololololololo." | ./wordcount -c 
echo "Hello \n world! \n   lololololololololo." | ./wordcount -l -w 
echo "Hello \n world! \n   lololololololololo." | ./wordcount -l -c 
echo "Hello \n world! \n   lololololololololo." | ./wordcount -w -c 
echo "Hello \n world! \n   lololololololololo." | ./wordcount 
