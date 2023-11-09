#! /bin/bash
echo -e "\n\n\n"
echo "############################Test 1 Result############################"
valgrind ./test1
echo -e "\n\n\n"
echo $"############################Test 2 Result############################"
valgrind ./test2
echo -e "\n\n\n"
echo "############################Test 3 Result############################"
./test3
echo -e "\n\n\n"
echo "############################Test 4 Result############################"
./test4
echo -e "\n\n\n"
echo "############################Test 5 Result############################"
valgrind ./test5
echo -e "\n\n\n"
echo "############################Test 6 Result############################"
valgrind ./test6
echo -e "\n\n\n"
echo "############################Test 7 Result############################"
valgrind ./test7
echo -e "\n\n\n"
echo "############################Test 8 Result############################"
valgrind ./test8
echo -e "\n\n\n"
echo "############################Test 9 Result############################"
valgrind ./test9
