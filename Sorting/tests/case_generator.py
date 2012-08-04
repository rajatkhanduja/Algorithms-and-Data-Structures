#!/usr/bin/python
# Author : Rajat Khanduja
# Script to generate test cases to test a sorting algorithm
# Arguments :-
#   1 - maximum_number_of_elements_to_be_sorted
#   2 - maximum_element (highest number allowed)
#   3 - number_of_test_cases

# The script generates an input_test file and an output test file for each test case. The input file is named "input/X" and output file is named "output/X", 
# where X is a number.

import sys
import random

maxSize = int (sys.argv[1])
maxElem = int (sys.argv[2])
N = int (sys.argv[3])


for i in range (0, N):
  inputTest  = open ("input/"  + str (i + 1), 'w')
  outputTest = open ("output/" + str (i + 1), 'w')
 
  n = random.randint (1, maxSize)
  arr = []
  inputTest.write (str(n) + "\n")
  for i in range (0, n):
    tmp = random.randint (1, maxElem) 
    arr.append (tmp)
    inputTest.write (str(tmp) + "\n")

  arr.sort()
  for i in range (0, n):
    outputTest.write (str(arr[i]) + "\n")
