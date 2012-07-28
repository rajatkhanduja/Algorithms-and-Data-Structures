#!/usr/bin/python
# Author : Rajat Khanduja
# Finding the next permutation of a given number, i.e. using the same digits construct the permutation that it is the smallest number greater than 
# the given number using only those digits.


def nextpermutation(n):
  nString = str(n)

  if len (nString) == 1:
    return nString
  
  i = len(nString) - 1
  # From the end of the string, find the first digit, such that it is less than the following digit
  while True:
    k = i
    i -= 1
  
    if nString[i] < nString[k]:
      j = len(nString) - 1

      while not (nString[i] < nString[j]):
        j -= 1

      tmp = nString[i + 1 : j] + nString[i] + nString[j + 1 : ]
      return nString[0 : i] + nString[j] + tmp[ : : -1]

    if i == 0:
      # Already the largest permutation. Give the next permutation, which is the smallest permutation
      return nString[ : : -1]


