#!/usr/bin/python
# Author : Rajat Khanduja
# Program to solve the maximum subarray problem using DP.

def maximumSubarray (arr):
  if len(arr) == 1:
    return (arr, arr[0])

  (a, aSum) = maximumSubarray (arr[:len(arr) - 1])
  maxSum = max(aSum, aSum + arr[len(arr) - 1], arr[len(arr) - 1])

  
  if maxSum == aSum:
    retArr = a
  elif maxSum == aSum + arr[len(arr) - 1]:
    retArr = a + [arr[len(arr) - 1]]
  else:
    retArr = [arr[len(arr) - 1]]

  return (retArr, maxSum)

print maximumSubarray ([-1,-2,3,-3])
