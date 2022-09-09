Instructions for Problem 1
1.) Start with entering hw 1 folder: 
cd hw1/

2.) To compile:
g++ -g -Wall -std=c++11 -c split.cpp

g++ -g -Wall -std=c++11 split_test.cpp split.cpp -o split

3.) To run:
./split_test.cpp

4.) To check valgrind: 
valgrind --tool=memcheck --leak-check=yes ./split


Instructions for Problem 2
1.) Start with entering hw 1 folder: 
cd hw1/

2.) To compile:
 g++ -g -Wall ulliststr.cpp ulliststr_test.cpp -o ulliststr_test

3.) To run:
./ulliststr_test.cpp

4.) To check valgrind:
valgrind --tool=memcheck --leak-check=yes ./ulliststr_test
