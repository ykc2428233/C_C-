EE 200 Homework 15

# Overview
This assignment is the reverse of most that you've written so far: I have written some implementations of a binary search tree (for integers), and you will write the tests.  Your job is to figure out which of the 9 implementations actually does what is described in the header file `btree.h`.  Bonus points will be awarded if you come up with a test that breaks all of them (i.e., you find a real bug in my code).

You can use the provided Makefile to compile your code and run all your tests.

# Submission
Zip up your `hw15` directory and submit it via `provide` as `hw15`.  It is due Friday 12/11 at 11:59pm.
You can use the following command to zip up the directory:
    zip -r hw15 hw15/*

# Problem
For each of the 9 implementations, write a 1-sentence description of what the implementation is doing wrong, or how you found that it is broken.

1. add() is wrong: The value added is not what I expected.
2. All correct.
3. remove() is wrong: After I remove the root node, the new root is NULL.
4. copy constructor is wrong: I construct bt2 with bt1, and they have the same root node.
5. remove() is wrong: remove function just remove the late element. 
6. remove() is wrong: I remove a non-exist element, and the program crashes.
7. contains() is wrong: The tree contains value when size is 0.
8. contains() is wrong: When checking extremly large tree, contains() can't check all the values in the tree. It looks like the size of 'contians list' is 40, contains() can check at most 40 elements.
9. = operator is wrong: When doing self assignment of bt4, the new root of bt4 is NULL. 

In addition to finding the errors, you'll be graded on the overall quality of your test code.  Submit all of the test code that you write!

